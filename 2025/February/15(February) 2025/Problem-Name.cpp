class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // Base case: If root is null
        if (!root) return NULL;

        // If both nodes are smaller, search in left subtree
        if (n1->data < root->data && n2->data < root->data)
            return LCA(root->left, n1, n2);

        // If both nodes are greater, search in right subtree
        if (n1->data > root->data && n2->data > root->data)
            return LCA(root->right, n1, n2);

        // If one node is on the left and the other on the right, root is LCA
        return root;
    }
};
