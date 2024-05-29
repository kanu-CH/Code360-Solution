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
#include <vector>
#include <map>
#include <queue>
vector<int> bottomView(TreeNode<int> * root){
    vector<int> ans;
    if(root == NULL) 
        return ans;

    map<int,int> topNode;
    queue<pair<TreeNode<int>*, int> > q;
        
    q.push(make_pair(root, 0));
        
    while(!q.empty()) {
        pair<TreeNode<int>*, int> temp = q.front();
        q.pop();
        TreeNode<int>* frontNode = temp.first;
        int hd = temp.second;
        topNode[hd] = frontNode -> data;
         if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }
    for(auto i:topNode) 
        ans.push_back(i.second);
    return ans;
}
