/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
   //Using Morris Traversal
    vector<int> res;
    TreeNode *current, *pre;
    if (root == NULL)
         return res;
        current = root;
        while (current != NULL) {
        if (current->left == NULL) {
            res.push_back(current->data);
            current = current->right;
        }
        else {
             /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
    
            /* Make current as the right child of its inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
    
            /* Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor */
            else {
                pre->right = NULL;
                res.push_back(current->data);
                current = current->right;
            } 
        } 
    }
    return res;
}
