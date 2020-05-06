#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:

        int data;
        TreeNode *left;
        TreeNode *right;

        friend void inOrderTraversal(TreeNode *);

        TreeNode(int data){

            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }

};

void inOrderTraversal(TreeNode *head){

    if(head){

        inOrderTraversal(head->left);
        cout<<head->data<<" ";
        inOrderTraversal(head->right);
    }

}

TreeNode *BuildTree(int arr[],int l,int r){

    if(l > r){
        return nullptr;
    }
    
    int mid = (l+r)/2;
    TreeNode *ptr = new TreeNode(arr[mid]);
    TreeNode *a = BuildTree(arr,l,mid-1);
    TreeNode *b = BuildTree(arr,mid+1,r);
    ptr->left = a;
    ptr->right = b;
    return ptr;
}


int main(int argc, const char** argv) {
    
    int arr[] = {1,2,3,4,5,6,7,8,9};

    TreeNode *head = BuildTree(arr,0,8);
    inOrderTraversal(head);

    return 0;
}