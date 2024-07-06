#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
      public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int countNodes(TreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isCBT(TreeNode<int>* root, int i, int cnt){
    if(root == NULL)
        return true;
    if(i >= cnt)
        return false;
    else{
        bool left = isCBT(root->left, 2*i+1, cnt);
        bool right = isCBT(root->right, 2*i+2, cnt);
        return(left&&right);
    }
}
int isCompleteBinaryTree(TreeNode<int> *root)
{
    int index = 0;
    int totalCount = countNodes(root);
    if(isCBT(root, index, totalCount))
        return 1;
    else 
        return 0;
}
