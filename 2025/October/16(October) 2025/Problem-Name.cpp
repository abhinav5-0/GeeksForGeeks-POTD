class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // Base case: if tree is empty
        if (!root) return NULL;

        // Recursively fix the left and right subtrees
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);

        // If root’s data is less than l, discard left subtree
        if (root->data < l) {
            Node* rightChild = root->right;
            delete root;  // free memory
            return rightChild;
        }

        // If root’s data is greater than r, discard right subtree
        if (root->data > r) {
            Node* leftChild = root->left;
            delete root;  // free memory
            return leftChild;
        }

        // If root’s data is within range, return root
        return root;
    }
};
