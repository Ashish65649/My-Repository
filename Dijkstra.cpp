#include<bits/stdc++.h>
using namespace std;

class Dijkstra{

    private:
        map<int,list<pair<int,int> > >m;
    public:
        void AddEdge(int src,int dest,int weight,bool bidirectional=true){

            pair<int,int> p;
            p = make_pair(dest,weight);
            m[src].push_back(p);
            if(bidirectional){
                p = make_pair(src,weight);
                m[dest].push_back(p);
            }
        }

        int ReturnIndex(map<int,int> &n){
            int min = INT_MAX;
            int index;
            map<int,int> :: iterator ir = n.begin();
            index = ir->first;
            for(auto x=ir;x!=n.end();x++){
                if(min > x->second){
                    index = x->first;
                    min = x->second;
                }
            }
            return index;
        }

        void Print(){

            map<int,list<pair<int,int> > > :: iterator it = m.begin();
            for(auto a=it; a!=m.end(); a++){
                cout<<a->first<<" -> [";
                list<pair<int,int> > p = a->second;
                for(auto x=p.begin();x!=p.end();x++){
                    pair<int,int> pr = *x;
                    cout<<"( "<<pr.first<<","<<pr.second<<" )";
                }
                cout<<"]"<<endl;
            }
        }

        int DIJKSTRA(int src,int dest){
            map<int,int> distance;
            distance[src] = 0;
            map<int,int> marked;
            map<int,int> ans;
            ans[src] = 0;
            map<int,list<pair<int,int> > > :: iterator it = m.begin();
            for(auto a=it; a!=m.end(); a++){
                if(a->first != src){
                    distance[a->first] = INT_MAX;
                }  
            }
            while(it++ != m.end()){
                int index = ReturnIndex(distance);
                list<pair<int,int> > l = m[index];
                for(auto s=l.begin();s!=l.end();s++){
                    pair<int,int> p = *s;
                    if(!marked[p.first]){
                        int dist = distance[index] + p.second;
                        distance[p.first] = min(distance[p.first],dist);
                        ans[p.first] = distance[p.first];
                    }
                }
                marked[index] = 1;
                distance.erase(index);
            }
            map<int,int> :: iterator h = ans.begin();
            for(auto f=h;f!=ans.end();f++){
                if(dest == f->first)
                    return f->second;
            }
        }
};

int main(){

    Dijkstra d;
    d.AddEdge(0,1,4);
    d.AddEdge(0,2,8);
    d.AddEdge(1,3,5);
    d.AddEdge(2,4,9);
    d.AddEdge(1,2,2);
    d.AddEdge(3,4,4);
    d.AddEdge(2,3,5);
    cout<<d.DIJKSTRA(0,2)<<endl;
    return 0;
}