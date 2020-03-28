#include<iostream>
#include<bitset>
using namespace std;
int counter=0;

bitset<30> col,ld,rd;

void SolveNQueen(int Board[][20],int i,int n){

    //Base case
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(Board[i][j] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        counter++;      //For counting all possible configuration of the queen on the chessboard
        return;      
    }
    
    //Recursive case
    else{
        for(int k=0;k<n;k++){
            if(!col[k] && !ld[i+k] && !rd[i-k+n-1]){
                col[k] = ld[i+k] = rd[i-k+n-1] = 1;
                Board[i][k] = 1;
                SolveNQueen(Board,i+1,n);
                col[k] = ld[i+k] = rd[i-k+n-1] = 0;    //Backtracking step
                Board[i][k] = 0;
            }
        }
    }
}

int main(){

    int n;
    cin>>n;
    int Board[20][20] = {0};
    SolveNQueen(Board,0,n);
    cout<<counter<<endl;
    return 0;
}
