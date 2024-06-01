/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void flattenBinaryTree(TreeNode<int>* root)
{
   TreeNode<int>* curr = root;
    while(curr != NULL){
        if(curr -> left){
            TreeNode<int>* pred = curr -> left;
            while(pred -> right)
                pred = pred->right;
                    
            pred -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        curr = curr -> right;
    }
}
