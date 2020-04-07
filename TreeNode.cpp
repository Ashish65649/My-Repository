class TreeNode{

    private:
        int data;
    public:
        TreeNode *left;
        TreeNode *right;
        TreeNode(int);
        static int getData(TreeNode *);
        static void UpdateNode(TreeNode *ptr,int Val){
            ptr->data = Val;
        }
};
TreeNode :: TreeNode(int data){

    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

int TreeNode :: getData(TreeNode *ptr){
    return ptr->data;
}