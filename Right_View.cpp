/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int>* root, vector<int> &ans, int level) {
        //base case
        if(root == NULL)
            return ;
           
        //we entered into a new level    
        if(level == ans.size())
            ans.push_back(root->data);
            
        solve(root->right, ans, level+1);    
        solve(root->left, ans, level+1);
        
    }
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
