#include <iostream>
#include<math.h>
using namespace std;

bool canPlace(int Suduko[][9],int x,int y,int number,int n)
{
//For rows  and column
for(int i=0;i<n;i++)
{
    if(Suduko[x][i] == number or Suduko[i][y] == number)
    {   
        return false;
    }
}

//For subgrid
int sroot = sqrt(n);
int a = (x/sroot)*sroot;
int b = (y/sroot)*sroot;
for(int i=a;i<(a+sroot);i++)
{
    for(int j=b;j<(b+sroot);j++)
    {
        if(Suduko[i][j] == number)
        {
            return false;
        }
    }
}
return true;
}
bool solveSudoKo(int Sudoko[][9],int row,int column,int n){

//All rows completed
if(row == n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<Sudoko[i][j]<<" ";
        }
        cout<<endl;
    }
    return true;
}

//Completion of one row
if(column == n)
{
    return solveSudoKo(Sudoko,row+1,0,n);
}

//Prefilled cells
if(Sudoko[row][column] != 0)
{
    return solveSudoKo(Sudoko,row,column+1,n);
}

for(int number=1;number<=n;number++)
{
    if(canPlace(Sudoko,row,column,number,n))
    {
        Sudoko[row][column] = number;
        bool b = solveSudoKo(Sudoko,row,column+1,n);
        if(b == true)
        {
            return true;
        }
    }
}
Sudoko[row][column] = 0;
return false;
}

int main()
{
int n;
cin>>n;

int Sudoko[9][9];
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cin>>Sudoko[i][j];
    }
}
solveSudoKo(Sudoko,0,0,n);
return 0;
}

