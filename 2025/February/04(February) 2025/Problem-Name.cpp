class Solution {
  public:
    int diameter(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

  private:
    int height(Node* node, int& diameter) {
        if (!node) return 0;

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        // Update the diameter if the path through this node is longer
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the tree rooted at this node
        return 1 + max(leftHeight, rightHeight);
    }
};
