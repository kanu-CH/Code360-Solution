#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure.
    
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
    };
    
*************************************************************/
void solve(BinaryTreeNode<int>* root, int targetSum, vector<int> &path, vector<vector<int>> &allPaths) {
    if (root == NULL)
        return;

    path.push_back(root->data);

    solve(root->left, targetSum, path, allPaths);
    solve(root->right, targetSum, path, allPaths);

    long long sum = 0;
    for (int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if (sum == targetSum) {
            vector<int> temp(path.begin() + i, path.end());
            allPaths.push_back(temp);
        }
    }

    path.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector<int> path;
    vector<vector<int>> allPath;
    solve(root, k, path, allPath);
    return allPath;
}
