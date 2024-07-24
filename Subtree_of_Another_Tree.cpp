/***************************************************
  Following is the TreeNode Structure

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

*****************************************************/

// Function to check if two trees are identical
bool isIdentical(TreeNode<int>* t1, TreeNode<int>* t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return true;
    }
    if (t1 == nullptr || t2 == nullptr) {
        return false;
    }
    return (t1->val == t2->val) && isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right);
}

// Function to check if tree S is a subtree of tree T
bool isSubtree(TreeNode<int>* T, TreeNode<int>* S) {
    if (T == nullptr) {
        return false;
    }
    if (S == nullptr) {
        return true;
    }
    if (isIdentical(T, S)) {
        return true;
    }
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}
