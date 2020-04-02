#include <bits/stdc++.h>
using namespace std;
int root;
// Complete the powerSum function below.
bool Func(int gamt,int n,int prevAmt,int i,int &count){
    if(prevAmt > gamt){
        return false;
    }
    if(gamt == prevAmt){
        count = count + 1;
        return false;
    }
    for(int j=i;j<=root;j++){
        int curAmt = prevAmt + (int)pow(j,n);
        bool v = Func(gamt,n,curAmt,j+1,count);
        if(v == false && curAmt == gamt){
            break;
        }
        if(v == false && curAmt > gamt){
            return false;
        }
    }
    return false;
}

int powerSum(int X, int N) {

    root = (int)sqrt(X);
    int count=0;
    if(Func(X,N,0,0,count) == true)
        return count/2;
    else{
        return count/2;
    }
}

int main(){

    cout<<powerSum(100,2)<<endl;
}