#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

bool isSpecialBinaryTree(BinaryTreeNode<int>* root)
{
    // If the tree is empty, it is considered special
    if (root == nullptr) {
        return true;
    }

    // If the node has only one child, return false
    if ((root->left == nullptr && root->right != nullptr) || 
        (root->left != nullptr && root->right == nullptr)) {
        return false;
    }

    // Recursively check the left and right subtrees
    bool leftSpecial = isSpecialBinaryTree(root->left);
    bool rightSpecial = isSpecialBinaryTree(root->right);

    return leftSpecial && rightSpecial;
}
