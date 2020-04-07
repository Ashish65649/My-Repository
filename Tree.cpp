#include<bits/stdc++.h>
#include "TreeNode.cpp"
using namespace std;

class Tree{

    private:
        int height;
        TreeNode *head;
        void PreOrder(TreeNode *);
        virtual void Insert(TreeNode *,int);
        void PostOrder(TreeNode *);
        void InOrder(TreeNode *);
        void LevelOrder(TreeNode *);
        void TopView(TreeNode *,int);
        void Height(TreeNode *,int );
        TreeNode *Delete(TreeNode*,int data);
        int Helper(TreeNode*);
    public:
        Tree();
        void InsertNode(int);
        int getHeight();
        void preorder();
        void postorder();
        void inorder();
        void levelorder();
        void topView();
        void Delete(int );
};

Tree :: Tree(){

    head = nullptr;
    height = 0;

}
vector<int> vet;
void Tree :: LevelOrder(TreeNode *ptr){

    queue<TreeNode *> q;
    q.push(ptr);
    while(!q.empty()){

        TreeNode *p = q.front();
        q.pop();
        cout<<TreeNode::getData(p)<<" ";
        vet.push_back(TreeNode::getData(p));
        if(p->left != nullptr)
            q.push(p->left);
        if(p->right != nullptr)
            q.push(p->right);
    }
    cout<<endl;
}

void Tree :: Height(TreeNode *ptr,int h){

    if(ptr){
        Height(ptr->left,h+1);
        Height(ptr->right,h+1);
    }
    else{
        height = max(h,height);
    }
}

int Tree :: getHeight(){

    Height(head,0);
    return height;
}

void Tree :: levelorder(){
    LevelOrder(head);
}

void Tree :: InOrder(TreeNode *ptr){

    if(ptr){
        InOrder(ptr->left);
        cout<<TreeNode::getData(ptr)<<" ";
        InOrder(ptr->right);
    }
}

void Tree :: PreOrder(TreeNode *ptr){

    if(ptr){
        cout<<TreeNode::getData(ptr)<<" ";
        PreOrder(ptr->left);
        PreOrder(ptr->right); 
    }
}

void Tree :: PostOrder(TreeNode *ptr){

    if (ptr){
        PostOrder(ptr->left);
        PostOrder(ptr->right);
        cout<<TreeNode::getData(ptr)<<" ";
    }
}

void Tree :: inorder(){

    InOrder(head);

}

void Tree :: postorder(){

    PostOrder(head);
}

void Tree :: preorder(){
    PreOrder(head);
}

void Tree :: Insert(TreeNode *head,int data){

    TreeNode *ptr = new TreeNode(data);
    if(data < TreeNode::getData(head)){

        if(head->left == nullptr){
            head->left = ptr;
            return;
        }
        Insert(head->left,data);
    }
    else{

        if(head->right == nullptr){
            head->right = ptr;
            return;
        }
        Insert(head->right,data);
    }
}

void Tree :: InsertNode(int data){

    if (head == nullptr){
        TreeNode *ptr = new TreeNode(data);
        head = ptr;
        return;
    }
    else{
        Insert(head,data);
    }
}
map<int,list<int> > m;
void Tree :: TopView(TreeNode *root,int hd){
    
    if(root){
        m[hd].push_back(TreeNode::getData(root));
        TopView(root->left,hd-1);
        TopView(root->right,hd+1);
    }
}

void Tree :: topView() {

     LevelOrder(head);
     TopView(head,0);
     int mn;
     map<int,list<int> > :: iterator it;
     for(it = m.begin();it!=m.end();it++){
         list<int> l = m[it->first];
         list<int> :: iterator iu = l.begin();
        if(l.size() == 1){
             cout<<*iu<<" ";
         }
         else{
             int index=0;
             mn = INT_MAX;
             for(auto io = l.begin();io!=l.end();io++){
                for(int i=0;i<vet.size();i++){
                    if(*io == vet.at(i)){
                        index = i;
                        break;
                    }
                }
                mn = min(mn,index);
             }
             cout<<vet.at(mn)<<" ";
         }
      }
      cout<<endl;
}

int Tree :: Helper(TreeNode *ptr){

    if(ptr == nullptr){
        return INT_MIN;
    }
    int leftMax = Helper(ptr->left);
    int rightMax = Helper(ptr->right);
    return max(max(leftMax,rightMax),TreeNode::getData(ptr));
}

TreeNode * Tree :: Delete(TreeNode *root,int data){

    if(root == nullptr){
        return root;
    }

    //Leaf Node
    else if(root->left == nullptr && root->right == nullptr && TreeNode::getData(root) == data){
        delete root;
        return nullptr;
    }

    //Node with single child(left child is null)
    else if((root->left == nullptr && root->right != nullptr) && TreeNode::getData(root) == data){
        TreeNode *ptr = root->right;
        delete root;
        return ptr;
    }

    //Node with single child(right child is null)
    else if((root->left != nullptr && root->right == nullptr) && TreeNode::getData(root) == data){
        TreeNode *ptr = root->left;
        delete root;
        return ptr;
    }
    //Node with 2 children
    else if((root->left != nullptr && root->right != nullptr) && TreeNode::getData(root) == data){
        int ans = Helper(root->left);
        Delete(ans);
        TreeNode::UpdateNode(root,ans);
    }

    else{
        root->left = Delete(root->left,data);
        root->right = Delete(root->right,data);
        return root;
    }

}

void Tree :: Delete(int data){

    head = Delete(head,data);
}

int main(){

    Tree t;
    t.InsertNode(8);
    t.InsertNode(4);
    t.InsertNode(10);
    t.InsertNode(2);
    t.InsertNode(6);
    t.InsertNode(9);
    t.InsertNode(11);
    t.Delete(5);
    t.levelorder();
}