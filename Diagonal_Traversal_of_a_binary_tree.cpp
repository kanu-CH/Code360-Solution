#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:
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

vector<int> diagonalTraversal(TreeNode<int> *root) {
    vector <int> diagonal;
    if(root==NULL) return diagonal;
   
    queue <TreeNode<int> *> q;
    q.push(root);
   
    while(!q.empty()){
       TreeNode<int> *temp = q.front();
       q.pop();
       
       while(temp!=NULL){
           diagonal.push_back(temp->data);
           q.push(temp->left);
           
           temp = temp->right;
       }
   }
   return diagonal;
}
