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
int getMaxDepth(TreeNode<int> *root, int &diameter) {
	if(root == NULL) {
		return 0;
	}
	int leftSubtreeDepth = getMaxDepth(root->left, diameter);
	int rightSubtreeDepth = getMaxDepth(root->right, diameter);
	diameter = max(diameter, leftSubtreeDepth + rightSubtreeDepth);
	return max(leftSubtreeDepth, rightSubtreeDepth) + 1;
}
int diameterOfBinaryTree(TreeNode<int> *root){
	int diameter = 0;
    getMaxDepth(root, diameter);
	return diameter;
}
