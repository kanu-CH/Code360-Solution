#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int>* root) {
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    if(!root->left)
        return solve(root->right) + 1;
    if(!root->right)
        return solve(root->left) + 1;

    int lheight = solve(root->left);
    int rheight = solve(root->right);
    
    return min(lheight,rheight) + 1;
    }
int minDepth(TreeNode<int>* root)
{
    return solve(root);
}
