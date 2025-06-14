class Solution {
  public:
    bool isMirror(Node* left, Node* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->data == right->data) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(Node* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
