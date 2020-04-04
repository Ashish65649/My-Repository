#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

class Graph{

    private:
        //friend void Helper(map<int,int> ,int ,map<int,list<int> >);
        map<int,list<int> > m;
    public:
        void AddEdge(int a,int b,bool bidirectional=true){
            m[a].push_back(b);
            if(bidirectional){
                m[b].push_back(a);
            }
        }
        void Print();
        int ConnectedComponentDFS(map<int,int>);
        int ConnectedComponentBFS(map<int,int>,int);
        void DFS(map<int,int> &,int);
        void BFSIterative(map<int,int>,queue<int>);
        void BFSRecursive(map<int,int>,queue<int>);
        map<int,int> ShortestPath(map<int,int>,queue<int>);
        bool CycleBFS(int);
        bool CycleDFS(int);

};

int Graph :: ConnectedComponentDFS(map<int,int> visited){

    int component=0;
    queue<int> q;
    for(auto it = m.begin();it!=m.end();it++){
        if(!visited[it->first]){
            ++component;
            DFS(visited,it->first);
        }
    }
    return component;
}

bool Graph :: CycleBFS(int src){

    queue<int> q;
    map<int,int> visited;
    q.push(src);
    visited[src] = 1;
    map<int,int> parent;
    parent[src] = -1;
    int data;
    while(!q.empty()){
        data = q.front();
        list<int> l = m[data];
        q.pop();
        for(int x : l){
            if(!visited[x]){
                q.push(x);
                visited[x] = 1;
                parent[x] = data;
            }
            else if(x != parent[data]){
                return true;
            }
        }
    }
    return false;
}

bool DfsHelper(map<int,int> &visited,int src,map<int,list<int> > &m,map<int,int> &parent){

    list<int> l = m[src];
    for(int x : l){
        if(!visited[x]) {
            parent[x] = src;
            visited[x] = 1;
            DfsHelper(visited,x,m,parent);
        }
        else if(x != parent[src]){
            return true;
        }
    }
    return false;
}

bool Graph :: CycleDFS(int src){

    map<int,int> visited;
    map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;
    return DfsHelper(visited,src,m,parent);
}

void Helper(map<int,int> &visited,int src,map<int,list<int> > &mp){
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()){

        int data = q.front();
        q.pop();
        list<int> l = mp[data];
        for(int x : l){
            if(!visited[x]){
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

int Graph :: ConnectedComponentBFS(map<int,int> visited,int src){

    int comp = 1;
    Helper(visited,src,m);
    for(auto it=m.begin();it!=m.end();it++){
        if(!visited[it->first]){
            Helper(visited,it->first,m);
            ++comp;
        }
    }
    return comp;
}

void Graph :: DFS(map<int,int> &visited,int q){

    //cout<<q<<" ";
    visited[q] = 1;
    list<int> li = m[q];
    for(int x : li){
        if(!visited[x])
            DFS(visited,x);
    }
}
map<int,int> Graph :: ShortestPath(map<int,int> visited,queue<int> q){

    map<int,int> distance;
    map<int,int> parent;
    int da = q.front();
    distance[q.front()] = 0;
    parent[q.front()] = -1;
    while(!q.empty()){

        int data = q.front();
        q.pop();
        list<int> li = m[data];
        for(int x : li){
            if(!visited[x]){
                q.push(x);
                visited[x] = 1;
                distance[x] = 6 + distance[data];
                parent[x] = data;
            }
        }
    }
    return distance;
}

void Graph :: Print(){

    map<int, list<int> >::iterator it;
    for (it = m.begin() ; it != m.end() ; it++){

        cout<<it->first<<"-> [ ";
        for(int x : it->second){

            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
}
void Graph :: BFSIterative(map<int,int> marked,queue<int> q){

    while (!q.empty())
    {
        int data = q.front();
        q.pop();
        cout<<data<<" ";
        list<int> k = m[data];
        for(int u : k){
            if(marked[u] != 1){
                q.push(u);
                marked[u] = 1;
            }
        }
    }
    cout<<endl;
}

void Graph :: BFSRecursive(map<int,int> marked,queue<int> q){

    if(q.empty() == true){
        return;
    }
    int data = q.front();
    q.pop();
    cout<<data<<" ";
    list<int> k = m[data];
    for(int u : k){
        if(marked[u] != 1){
            q.push(u);
            marked[u] = 1;
        }
    }
    BFSRecursive(marked,q);
}

// int main(){

//     Graph g;
//     g.AddEdge(1,2);
//     g.AddEdge(1,3);
//     g.AddEdge(2,3);
//     // g.AddEdge(4,3);
//     // g.AddEdge(4,5);
//     //g.AddEdge(5,2);
//     if(g.CycleDFS(1)){
//         cout<<"Graph is cyclic\n";
//     }
//     else{
//         cout<<"Graph is not cyclic\n";
//     }
//     map<int,int> visited;
//     return 0;
// }