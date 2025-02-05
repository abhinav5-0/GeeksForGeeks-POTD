class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }
        
        // Swap left and right child
        swap(node->left, node->right);
        
        // Recursively call mirror on left and right subtree
        mirror(node->left);
        mirror(node->right);
    }
};
