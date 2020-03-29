#include<iostream>
#include<iomanip>
using namespace std;
int count=0;
int rowDir[] = {+2,+1,-1,-2,-2,-1,+1,+2};
int colDir[] = {+1,+2,+2,+1,-1,-2,-2,-1};

bool canPlace(int Board[][8],int row,int col,int n){

    if(row<0 || col <0 || row>=n || col >=n || Board[row][col] != 0){
        return false;
    }
    return true;
}

bool SolveKnightProblem(int Board[][8],int curRow,int curCol,int move,int n){

    if(move == (n*n)){                  //Base case
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<setw(3)<<Board[i][j]<<" ";
            }
            cout<<endl;
        }
        count++;
        cout<<"==============================================\n";
        return false;
    }
    for(int ways=0;ways<8;ways++){     //There can be 8 ways for a knight to move around its position

        int nextRow = curRow + rowDir[ways];
        int nextCol = curCol + colDir[ways];
        if(canPlace(Board,nextRow,nextCol,n)){
            Board[nextRow][nextCol] = move + 1;
            bool b = SolveKnightProblem(Board,nextRow,nextCol,move+1,n);
            // if(b == true){
            //     return true;
            // }
            Board[nextRow][nextCol] = 0;
        }
    }
    return false;
}
int main(){

    int Board[8][8] = {0};
    Board[0][0] = 1;                 //Placed knight in (0,0)
    int n;
    cin>>n;
    SolveKnightProblem(Board,0,0,1,n);
    cout<<"\n"<<count<<endl;
    return 0;
}