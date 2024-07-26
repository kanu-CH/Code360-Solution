#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        bool isOriginal;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int nodeLevel(TreeNode<int>* root, int searchedValue)
{
    if (root == NULL) {
        return 0;
    }

    // Queue for level-order traversal
    queue<TreeNode<int>*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            TreeNode<int>* currentNode = q.front();
            q.pop();

            if (currentNode->val == searchedValue) {
                return level;
            }

            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }

        ++level;
    }

    // If we exit the loop without finding the node, it is not present in the tree
    return 0;
}
