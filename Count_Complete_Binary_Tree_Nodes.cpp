#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
int solve(TreeNode<int> *root){
        //base case
        if(root==NULL) 
            return 0;
        //recursive call
        return 1+solve(root->left)+solve(root->right);
    }
int countNodes(TreeNode<int> *root)
{
    return solve(root);
}
