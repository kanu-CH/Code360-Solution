/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Find the key
    TreeNode* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp != NULL && temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    if(temp == NULL) {
        // Key not found in the tree
        return make_pair(pred, succ);
    }

    // Find the predecessor (max value in left subtree)
    if(temp->left != NULL){
        TreeNode* leftTree = temp->left;
        while(leftTree->right != NULL){
            leftTree = leftTree->right;
        }
        pred = leftTree->data;
    }

    // Find the successor (min value in right subtree)
    if(temp->right != NULL){
        TreeNode* rightTree = temp->right;
        while(rightTree->left != NULL){
            rightTree = rightTree->left;
        }
        succ = rightTree->data;
    }

    return make_pair(pred, succ);
}
