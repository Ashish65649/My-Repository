#include<bits/stdc++.h>
using namespace std;

int Merge(int *p,int i,int j){

    int temp[100];
    int mid = (i+j)/2;
    int l = i;
    int g = (mid+1);
    int k = i;
    int res=0;
    while(l<=mid && g<=j){
        if(p[l] <= p[g]){
            temp[k++] = p[l++];
        }
        else{
            res += (mid+1-l);
            temp[k++] = p[g++];
        }
    }
    while(l<=mid){
        temp[k++] = p[l++];
    }
    while(g<=j){
        temp[k++] = p[g++];
    }
    for(int f=i;f<=j;f++){
        p[f] = temp[f];
    }
    return res;
}

int MergeSort(int *p,int i,int j){

    if(i == j){
        return 0;
    }
    int mid = (i+j)/2;
    int ICLeft = MergeSort(p,i,mid);
    int ICRight = MergeSort(p,mid+1,j);
    int CRInversion = Merge(p,i,j);
    return (ICLeft+CRInversion+ICRight);
}

int InversionCount(int *arr,int n){

    int ans = MergeSort(arr,0,n);
    return ans;
}

int main(){

    int n;
    cin>>n;
    int * arr = new int[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<InversionCount(arr,n-1)<<endl;
}