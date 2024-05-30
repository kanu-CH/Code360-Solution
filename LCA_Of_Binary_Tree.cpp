/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	// Base case
    if (root == NULL)
        return -1;
    if (root->data == x || root->data == y)
        return root->data;

    // Recur for left and right subtrees
    int leftAns = lowestCommonAncestor(root->left, x, y);
    int rightAns = lowestCommonAncestor(root->right, x, y);

    // If both left and right subtrees return non -1, then one node is present in one subtree and the other in the other subtree
    if (leftAns != -1 && rightAns != -1)
        return root->data;

    // If only one of the subtrees returns a non -1, return that one
    return (leftAns != -1) ? leftAns : rightAns;
}
