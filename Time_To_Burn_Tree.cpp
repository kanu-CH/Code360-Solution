/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map> 
BinaryTreeNode<int>* createParentMapping(BinaryTreeNode<int>* root, int target, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& nodeToParent) {
    BinaryTreeNode<int>* res = nullptr;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    nodeToParent[root] = nullptr;

    while (!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        if (front->data == target) {
            res = front;
        }

        if (front->left) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int burnTree(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& nodeToParent) {
    if (!root) 
        return 0;
    
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;

    while (!q.empty()) {
        int size = q.size();
        bool flag = false;

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int>* front = q.front();
            q.pop();

            if (front->left && !visited[front->left]) {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right]) {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        if (flag) {
            ans++;
        }
    }

    return ans;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> nodeToParent;
    BinaryTreeNode<int>* targetNode = createParentMapping(root, start, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
