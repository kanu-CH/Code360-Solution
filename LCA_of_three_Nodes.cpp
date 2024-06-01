/**********************************************************
    Following is the Binary Tree Node class structure.

    template <typename T>
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

***********************************************************/

BinaryTreeNode<int>* findLCA(BinaryTreeNode<int>* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    BinaryTreeNode<int>* leftLCA = findLCA(root->left, n1, n2);
    BinaryTreeNode<int>* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    BinaryTreeNode<int>* lca1 = findLCA(root, node1, node2);
    BinaryTreeNode<int>* lca2 = findLCA(root, lca1->data, node3);
    return lca2;
}
