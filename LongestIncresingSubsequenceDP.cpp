#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int LIS(int *p, int n){
    int dp[100];
    for(int k=0;k<=n;k++){
        dp[k]=1;
    }
    int mx = dp[0];
    for(int  i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j]<=p[i]){
                int rs = 1+dp[j];
                dp[i] = max(rs, dp[i]);
            }
        }
        mx = max(mx, dp[i]);
    }
    return mx;
}

int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	int *arr = new int[n+1];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	int result = LIS(arr, n);
	cout<<result<<endl;
}