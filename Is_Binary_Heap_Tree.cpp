#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
// Function to count the number of nodes in the binary tree
int countNodes(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to check if the tree is a complete binary tree
bool isCBT(BinaryTreeNode<int>* root, int index, int count) {
    if (root == NULL)
        return true;
    if (index >= count)
        return false;
    return isCBT(root->left, 2 * index + 1, count) && isCBT(root->right, 2 * index + 2, count);
}

// Function to check if the tree follows max-heap property
bool isMaxOrder(BinaryTreeNode<int>* root) {
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->right == NULL)
        return (root->data >= root->left->data);
    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return left && right && (root->data >= root->left->data) && (root->data >= root->right->data);
    }
}

// Main function to check if the tree is a binary heap tree
bool isBinaryHeapTree(BinaryTreeNode<int>* root) {
    int index = 0;
    int totalCount = countNodes(root);
    return isCBT(root, index, totalCount) && isMaxOrder(root);
}
