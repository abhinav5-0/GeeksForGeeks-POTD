class Solution {
  public:
    // Function to count total nodes
    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Function to check completeness
    bool isComplete(Node* root, int index, int totalNodes) {
        if (root == NULL) return true;
        
        if (index >= totalNodes) return false;
        
        return isComplete(root->left, 2 * index + 1, totalNodes) &&
               isComplete(root->right, 2 * index + 2, totalNodes);
    }
    
    // Function to check max-heap property
    bool isMaxHeap(Node* root) {
        if (root == NULL) return true;
        
        // Leaf node
        if (!root->left && !root->right) return true;
        
        // Node with only left child
        if (root->left && !root->right)
            return (root->data >= root->left->data) && isMaxHeap(root->left);
        
        // Node with both children
        if (root->left && root->right)
            return (root->data >= root->left->data) && 
                   (root->data >= root->right->data) && 
                   isMaxHeap(root->left) &&
                   isMaxHeap(root->right);
        
        return false; // Should never reach here
    }
    
    bool isHeap(Node* tree) {
        int totalNodes = countNodes(tree);
        if (isComplete(tree, 0, totalNodes) && isMaxHeap(tree))
            return true;
        else
            return false;
    }
};
