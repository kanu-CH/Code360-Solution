/*************************************************************

    Following is the Binary Tree node structure:

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
void inorder(TreeNode* root, vector<int>&arr){
    if(root==NULL){
        return ;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
// Use this function to create the BST
// TreeNode* inOrderToBST(int s, int e, vector<int> &arr){
//     if(s>e){
//         return NULL;
//     }
//     int mid=s+(e-s)/2;
//     TreeNode* root= new TreeNode(arr[mid]);
//     root->left=inOrderToBST(s, mid-1, arr);
//     root->right=inOrderToBST(mid+1, e, arr);

//     return root;

// }
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    if(!root1 && !root2)
        return {};
    
    vector<int>arr;
    inorder(root1, arr);
    inorder(root2, arr);
    sort(arr.begin(), arr.end());
    return arr;
    // TreeNode* newNode=inOrderToBST(0, arr.size()-1, arr);
    // return newNode;
}
