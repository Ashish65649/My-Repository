#include<bits/stdc++.h>
using namespace std;

int Func(int *p,int amt,int n){

    int dp[n][amt+1];
    memset(dp,0,sizeof(dp));
    int i;
    for(i=0;i<n;i++){
        for(int j=0;j<=amt;j++){
            if(j==0){
                dp[i][j] = 1;
            }
            else{
                if(i==0){
                    if(j%p[i] == 0){
                        dp[i][j] = 1;
                    }
                }
                else {
                    if(j<p[i]){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i-1][j] + dp[i][j-p[i]];
                    }
                }
            }
        }
    }
    return dp[i-1][amt];
}

int main(){

    int arr[] = {1,2,3};
    int amount = 4;
    int n = sizeof(arr)/sizeof(int);
    int ways = Func(arr,amount,n);
    cout<<ways<<endl;
    return 0;
}