#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
BinaryTreeNode<int> *getBST(vector<int>& preorder,int maxi,int &index){
        if(index==preorder.size()|| preorder[index]>maxi ){
            return NULL;
        }

        BinaryTreeNode<int> *root=new BinaryTreeNode<int>(preorder[index++]);
        root->left=getBST(preorder,root->data,index);
        root->right=getBST(preorder,maxi,index);

        return root;
    }
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int index=0;
    return getBST(preorder,INT_MAX,index);
}
