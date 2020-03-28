#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >s;

void SubsetGenerator(int *primes,int n,int data){

    int total = (1<<n)-1;
    int res = 0;
    vector<int> v;
    for(int i=1;i<=total;i++){

        int temp = i;
        int k = 0;
        v.clear();
        while(temp > 0){
            
            int d = temp&1;
            if(d)
                v.push_back(primes[k]);
            temp = temp >> 1;
            ++k;
        }
        int sum = 0;
        for(int x : v){
            sum += x;
        }
        if(sum == data){
            s.push_back(v);
        }
    }
}

int main(){

    int n;
    cin>>n;
    int *primes = new int[n];
    for(int i=0;i<n;i++){
        cin>>primes[i];
    }
    int sum;
    cin>>sum;
    SubsetGenerator(primes,n,sum);
    for(vector<int> x : s){
        for(int r : x){
            cout<<r<<" ";
        }
        cout<<"  ";
    }
    cout<<"\n"<<s.size()<<endl;
    return 0;
}