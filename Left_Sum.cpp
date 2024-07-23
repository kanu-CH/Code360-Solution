#include <bits/stdc++.h> 
/*
	Tree Node class.

	class BinaryTreeNode 
	{
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
	}
*/
long long leftSumHelper(BinaryTreeNode<int>* node, bool isLeft) {
    if (node == NULL) {
        return 0;
    }

    long long sum = 0;
    if (isLeft) {
        sum += node->data;
    }

    sum += leftSumHelper(node->left, true);
    sum += leftSumHelper(node->right, false);

    return sum;
}

long long leftSum(BinaryTreeNode<int> *root)
{
	if (root == NULL) {
        return 0;
    }

    return leftSumHelper(root, false);
}
