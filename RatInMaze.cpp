#include<bits/stdc++.h>
using namespace std;
int ar[1010][1010];
bool RatInMaze(char arr[1010][1010] ,int i,int j,int m,int n){

    if(i==m && j==n){
        arr[i][j] = '1';
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(arr[i][j] == '1'){
					ar[i][j] = 1;
				}
				if(arr[i][j] == 'X' || arr[i][j] == '0'){
					ar[i][j] = 0;
				}
            }
        }
        return true;
    }
    if(j>n || i>m){
        return false;
    }
    if(arr[i][j] == 'X'){
        return false;
    }
    arr[i][j] = '1';
    bool b = RatInMaze(arr,i,j+1,m,n);
    if(b == true){
        return true;
    }
    bool c = RatInMaze(arr,i+1,j,m,n);
    if(c == true){
        return true;
    }
    if(b == false && c == false){
        arr[i][j] = '0';          //Backtracking step
        return false;
    }
}

int main(){

    char arr[1010][1010];
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>arr[i][j];
		}
	}
    bool g = RatInMaze(arr,0,0,a-1,b-1);
    if(g == true){
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cout<<ar[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(g == false){
		cout<<-1;
	}
    return 0;
}