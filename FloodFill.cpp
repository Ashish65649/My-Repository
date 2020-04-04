#include<iostream>
#include "Graph.cpp"
void Print(char arr[][20]);
void FloodFill(char mat[][20] ,int row,int col,int i,int j){

    if(i<0 || i>=row || j<0 || j>=col){
        return;
    }
    if(mat[i][j] != '.'){
        return;
    }
    mat[i][j] = 'R';
    Print(mat);
    cout<<endl;
    FloodFill(mat,row,col,i,j+1);
    FloodFill(mat,row,col,i,j-1);
    FloodFill(mat,row,col,i-1,j);
    FloodFill(mat,row,col,i+1,j);
}

void Print(char mat[][20]){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}

int main(){

    Graph g;
    char mat[20][20] = {  {"*******************"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*.................*"},
                          {"*******************"}
                    };
    FloodFill(mat,20,20,3,3);
    return 0;
}