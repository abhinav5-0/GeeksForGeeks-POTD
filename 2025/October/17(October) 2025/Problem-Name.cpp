/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int sum = 0;  // maintains sum of visited nodes

    void transformTree(Node *root) {
        if (!root) return;

        // Traverse right subtree first (greater values)
        transformTree(root->right);

        // Store original node value
        int old_val = root->data;

        // Update node with sum of greater nodes
        root->data = sum;

        // Update sum by adding old value
        sum += old_val;

        // Traverse left subtree
        transformTree(root->left);
    }
};
