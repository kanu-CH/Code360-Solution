#include <bits/stdc++.h>
void findMaxSumPath(BinaryTreeNode<int>* node, vector<int>& currentPath, int currentSum, int& maxSum, vector<int>& maxSumPath) {
    if (!node) return;

    // Include the current node in the path and add its value to the current sum
    currentPath.push_back(node->data);
    currentSum += node->data;

    // If it's a leaf node, check if this path has the maximum sum
    if (!node->left && !node->right) {
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxSumPath = currentPath;
        }
    }

    // Recur for left and right subtrees
    findMaxSumPath(node->left, currentPath, currentSum, maxSum, maxSumPath);
    findMaxSumPath(node->right, currentPath, currentSum, maxSum, maxSumPath);

    // Backtrack: remove the current node from the path
    currentPath.pop_back();
}

vector<int> maxSum(BinaryTreeNode<int> *root) {
    vector<int> maxSumPath;
    vector<int> currentPath;
    int maxSum = INT_MIN;
    findMaxSumPath(root, currentPath, 0, maxSum, maxSumPath);
    reverse(maxSumPath.begin(), maxSumPath.end());
    return maxSumPath;
}
