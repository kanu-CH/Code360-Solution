/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* solve(int &Postindex,int inI,int inJ,vector<int>&inorder, vector<int>&postorder)
{
    if(Postindex<0 || inI>inJ) 
    {
        return NULL;
    }
    TreeNode<int>* root=new TreeNode<int>(postorder[Postindex--]);
    int i;
    for( i=inI;i<=inJ;i++)
    {
        if(inorder[i]==root->data)
        {
            break;
        }
    }
    root->right=solve(Postindex,i+1,inJ,inorder,postorder); 
    root->left=solve(Postindex,inI,i-1,inorder,postorder);
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	int index=postOrder.size()-1;
     return solve(index,0,inOrder.size()-1,inOrder,postOrder);
}
