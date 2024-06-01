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
int Findposition(vector<int>& in ,int inorderStart , int inorderEnd , int element ,int  n){
    for(int i = inorderStart ; i<=inorderEnd ;i++){
        if(in[i]==element)
            return i ; 
    }
    return -1 ;
}
TreeNode<int>* solve(vector<int>& in,vector<int>& pre, int &index ,int inorderStart , int inorderEnd , int n){
    if(index>=n || inorderStart>inorderEnd)
        return NULL ;
        
    int element = pre[index++] ; 
    TreeNode<int>* root  = new TreeNode<int>(element); 
    int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
    root->left = solve(in , pre , index  , inorderStart , position-1 ,n);
    root->right = solve(in , pre , index , position+1 , inorderEnd ,n);
        
    return root ;  
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int n = inorder.size(); 
    int preorderindex  = 0 ;  
    TreeNode<int>* ans = solve(inorder , preorder , preorderindex , 0  , n-1 , n );
    return ans;
}
