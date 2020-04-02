#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int *p,int n){
    int flag = 0;
    for(int i=0;i<n;i++){
        flag = 1;
        for(int j=0;j<(n-i);j++){
            if(p[j] > p[j+1]){
                swap(p[j],p[j+1]);
                flag = 0;
            }
        }
        if(flag == 1){
            break;
        }
    }
}

void RecBubbleSort(int *p,int i,int n){

    if(i==n){
        return;
    }
    else{
        for(int j=0;j<(n-i);j++){
            if(p[j] > p[j+1]){
                swap(p[j],p[j+1]);
            }
        }
        RecBubbleSort(p,i+1,n);
    }

}

void PureRecBubbleSort(int *p,int i,int j,int n){

    if(i==n){
        return;
    }
    if(j==n){
        PureRecBubbleSort(p,i+1,0,n);
    }
    else{
        if(p[j] > p[j+1]){
            swap(p[j],p[j+1]);
        }
        PureRecBubbleSort(p,i,j+1,n);
    }
}

int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    BubbleSort(arr,n);
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}