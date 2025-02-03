class Solution {
public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // Base case: if the node is null, return -1
        if (node == NULL) {
            return -1;
        }
        
        // Recursively calculate the height of the left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // The height of the current node is the maximum of the left and right heights plus 1
        return max(leftHeight, rightHeight) + 1;
    }
};
