class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if (root == NULL)
            return 0;

        // If node value lies within [l, r]
        if (root->data >= l && root->data <= r)
            return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);

        // If node value is greater than r, go to left subtree
        else if (root->data > r)
            return nodeSum(root->left, l, r);

        // If node value is smaller than l, go to right subtree
        else
            return nodeSum(root->right, l, r);
    }
};
