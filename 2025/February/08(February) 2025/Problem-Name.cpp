class Solution {
  public:
    // Function to check if a node is a leaf node
    bool isLeaf(Node* node) {
        return (node && !node->left && !node->right);
    }

    // Function to get the left boundary (excluding leaf nodes)
    void leftBoundary(Node* node, vector<int>& result) {
        while (node) {
            if (!isLeaf(node)) result.push_back(node->data);
            node = (node->left) ? node->left : node->right;
        }
    }

    // Function to get all leaf nodes (left to right)
    void leafNodes(Node* node, vector<int>& result) {
        if (!node) return;
        if (isLeaf(node)) {
            result.push_back(node->data);
            return;
        }
        leafNodes(node->left, result);
        leafNodes(node->right, result);
    }

    // Function to get the right boundary in reverse order (excluding leaf nodes)
    void rightBoundary(Node* node, vector<int>& result) {
        vector<int> temp;
        while (node) {
            if (!isLeaf(node)) temp.push_back(node->data);
            node = (node->right) ? node->right : node->left;
        }
        // Add right boundary in reverse order
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }

    // Function to return the boundary traversal of a binary tree
    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};

        vector<int> result;

        // Root node (Only add if it's not a leaf)
        if (!isLeaf(root)) result.push_back(root->data);

        // Left boundary (excluding leaf nodes)
        leftBoundary(root->left, result);

        // Leaf nodes (from left to right)
        leafNodes(root, result);

        // Right boundary (in reverse order, excluding leaf nodes)
        rightBoundary(root->right, result);

        return result;
    }
};
