#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
// Helper function to perform inorder traversal and store nodes in a vector
void inorderTraversal(BinaryTreeNode* root, vector<int>& nodes) {
    if (root == NULL) return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inorderTraversal(root->right, nodes);
}

// Helper function to construct a Min Heap from a sorted array
BinaryTreeNode* constructMinHeap(vector<int>& sortedArray, int& index) {
    if (index >= sortedArray.size()) return NULL;

    BinaryTreeNode* root = new BinaryTreeNode(sortedArray[index]);
    index++;

    root->left = constructMinHeap(sortedArray, index);
    root->right = constructMinHeap(sortedArray, index);

    return root;
}

// Function to convert BST to Min Heap
BinaryTreeNode* convertBST(BinaryTreeNode* root) {
    // Step 1: Perform inorder traversal to get sorted array
    vector<int> sortedArray;
    inorderTraversal(root, sortedArray);

    // Step 2: Construct Min Heap from sorted array
    int index = 0;
    return constructMinHeap(sortedArray, index);
}
