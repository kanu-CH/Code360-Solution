/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
// Helper function to perform in-order traversal and collect nodes
void inorderTraversal(TreeNode<int>* root, vector<int>& nodes) {
    if (root == NULL)
        return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inorderTraversal(root->right, nodes);
}

// Helper function to build a balanced BST from sorted array
TreeNode<int>* buildBalancedBST(vector<int>& nodes, int start, int end) {
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode<int>* node = new TreeNode<int>(nodes[mid]);
    node->left = buildBalancedBST(nodes, start, mid - 1);
    node->right = buildBalancedBST(nodes, mid + 1, end);
    return node;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    if (root == NULL)
        return NULL;
        
    vector<int> nodes;
    inorderTraversal(root, nodes);
    return buildBalancedBST(nodes, 0, nodes.size() - 1);
}
