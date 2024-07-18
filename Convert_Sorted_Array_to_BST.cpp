#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* constructBST(const vector<int>& arr, int left, int right) {
        if (left > right){
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode<int>* node = new TreeNode<int>(arr[mid]);
        node->left = constructBST(arr, left, mid - 1);
        node->right = constructBST(arr, mid + 1, right);
        
        return node;
    }
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return constructBST(arr, 0, n - 1);
}
