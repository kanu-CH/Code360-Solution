#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        vector<TreeNode<T> *> child;
	    TreeNode(T data)
	    {
		    this->data = data;
	    }
    };

************************************************************/

vector<int> levelOrder(TreeNode<int> *root)
{
    // If the tree is empty
    if (root == nullptr) return {};

    // Initialize the result vector
    vector<int> result;

    // Initialize a queue for BFS
    queue<TreeNode<int> *> q;
    q.push(root);

    // Perform BFS
    while (!q.empty()) {
        // Get the front node in the queue
        TreeNode<int> *current = q.front();
        q.pop();

        // Add the current node's data to the result
        result.push_back(current->data);

        // Push all its child nodes to the queue
        for (auto childNode : current->child) {
            if (childNode != nullptr) {
                q.push(childNode);
            }
        }
    }

    // Return the result
    return result;
}
