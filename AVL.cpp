#include<iostream>
#include<queue>
using namespace std;
class AVLTree{

    private:
        class Node {

            public:
                int data;
                Node * left;
                Node * right;
                int height;

            Node(int data){
                this->data = data;
                this->left = nullptr;
                this->right = nullptr;
                this->height = 1;
            }
        };

    Node *head;

    Node * LLRotation(Node *root){
    
        //Data Store for future rotation
        Node *b = root->left;
        Node *p = b->right;
        //Code for rotating
        b->right = root;
        root->left = p;
        //Height Update
        root->height = max(Height(root->left),Height(root->right)) + 1;
        b->height = max(Height(b->left),Height(b->right)) + 1;
        return b;
    }

    Node *RRRotation(Node *root){

        //Data Store for future rotation
        Node *b = root->right;
        Node *p = b->left;
        //Code for rotating
        b->left = root;
        root->right = p;
        //Height Update
        root->height = max(Height(root->left),Height(root->right)) + 1;
        b->height = max(Height(b->left),Height(b->right)) + 1;
        return b;
    }

    Node *Insert(Node *root,int data){

        Node *ptr = new Node(data);
        if(data < root->data){
            if(root->left != nullptr){
                root->left = Insert(root->left,data);
            }
            else{
                root->left = ptr;
            }
        }
        else if(data > root->data){
            if(root->right != nullptr){
                root->right = Insert(root->right,data);
            }
            else{
                root->right = ptr;
            }
        }
        root->height = root->height + 1;
        int bf = (Height(root->left) - Height(root->right));

        if(bf > 1 && (data < root->left->data)){
            root = LLRotation(root);
        }
        else if(bf < -1 && (data > root->right->data)){
            root = RRRotation(root);
        }
        else if(bf > 1 && (data > root->left->data)){
            root->left = RRRotation(root->left);
            return LLRotation(root);
        }
        else if(bf < -1 && (data < root->right->data)){
            root->right = LLRotation(root->right);
            return RRRotation(root);
        }
        return root;
    }

    int Height(Node *ptr){
        if(ptr == nullptr){
            return 0;
        }
        return ptr->height;
    }

    public:
        AVLTree(){

            head = nullptr;
        }

        void LevelOrder(){

            Node *ptr = head;
            queue<Node *> q;
            q.push(ptr);
            while(!q.empty()){
                Node *p = q.front();
                q.pop();
                cout<<p->data<<" ";
                if(p->left != nullptr)
                    q.push(p->left);
                if(p->right != nullptr)
                    q.push(p->right);
            }
            cout<<endl;
        }

        void Insert(int data){
            Node *ptr = new Node(data);
            if(head == nullptr){
                head = ptr;
                return;
            }
            else{
                head = Insert(head,data);
            }
        }
};
int main(){

    AVLTree t;
    t.Insert(10);
    t.Insert(20);
    t.Insert(30);
    t.Insert(40);
    t.Insert(50);
    t.Insert(25);
    t.LevelOrder();
    return 0;
}