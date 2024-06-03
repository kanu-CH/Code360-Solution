#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
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
void inorder(BinaryTreeNode<int> *root,vector<int> &v){ 
    if(root==NULL)
        return ;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

bool validateBST(BinaryTreeNode<int>* root) 
{
    vector<int> v;
    inorder(root,v);

    for(int i=1;i<v.size();i++){
        if(v[i] <= v[i-1]){
                return false;
                break;
            }
        }
        return true;
}
