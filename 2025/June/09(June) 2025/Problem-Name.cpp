class Solution {
  public:
    bool checkDeadEnd(Node* root, int minVal, int maxVal) {
        if (!root) return false;

        // If min and max converge, we can't insert anything more
        if (minVal == maxVal) return true;

        // Check recursively for left and right subtrees
        return checkDeadEnd(root->left, minVal, root->data - 1) ||
               checkDeadEnd(root->right, root->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return checkDeadEnd(root, 1, INT_MAX);
    }
};
