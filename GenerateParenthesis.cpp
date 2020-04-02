#include<bits/stdc++.h>
using namespace std;
char arr[25];
vector<string> vec;

bool compare(string a,string b){
    return a>b;
}

void GenerateParenthesis(int n,int opening,int closing,int pos){

    if(pos == 2*n){
        arr[pos] = '\0';
        vec.push_back(arr);
        return;
    }
    else{

        if(opening < n){
            arr[pos] = '(';
            GenerateParenthesis(n,opening+1,closing,pos+1);
        }
        if(closing < opening){
            arr[pos] = ')';
            GenerateParenthesis(n,opening,closing+1,pos+1);
        }
    }
}

int main(){

    int n;
    cin>>n;
    GenerateParenthesis(n,0,0,0);
    sort(vec.begin(),vec.end(),compare);
    for(string x : vec){
        cout<<x<<endl;
    }
    return 0;
}