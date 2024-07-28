#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while (!q.empty()) {
        BinaryTreeNode<int>* current = q.front();
        q.pop();
        
        result.push_back(current->val);
        
        if (current->left != NULL) {
            q.push(current->left);
        }
        
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    
    return result;
}
