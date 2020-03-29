#include<bits/stdc++.h>
using namespace std;

int counter = 0;
bool isSafe(int Board[][25],int x,int y,int n){

    //For Column
    int a = x;
    int b = y;
    int flag = 0;
    for(int i=a-1;i>=0;i--){
        if(Board[i][b] == 1){
            return false;
        }
    }
    
    //For left diagonal
    if(x>0 && y>0 && Board[x-1][y-1] != 0){
        return false;
    }
    //For right diagonal
    if(x>0 && Board[x-1][y+1] != 0){
        return false;
    }
    return true;
}

void SolveNQueen(int Board[][25],int i,int n){

    //Base case
    if(i==n){
        counter++;  //true is returned from the function when we want our function to just return after printing the first 
                    //configuration of the queen on the board.
        return;   //For counting all possible configuration of the queen on the chessboard
    }                  
    
    //Recursive case
    else{
        for(int k=0;k<n;k++){
            if(isSafe(Board,i,k,n)){
                Board[i][k] = 1;
                SolveNQueen(Board,i+1,n);
                Board[i][k] = 0;    //Backtracking step
            }
        }
    }
}

int main(){

    int n;
    cin>>n;
    int Board[25][25] = {0};
    SolveNQueen(Board,0,n);
    cout<<counter<<endl;
    return 0;
}
