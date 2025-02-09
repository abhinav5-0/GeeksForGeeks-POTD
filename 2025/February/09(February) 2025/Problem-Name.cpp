class Solution {
  public:
    int maxPathSumUtil(Node* root, int &res) {
        if (root == NULL) return 0;

        // Compute the maximum path sum from left and right subtrees
        int leftSum = max(0, maxPathSumUtil(root->left, res));
        int rightSum = max(0, maxPathSumUtil(root->right, res));

        // Compute the maximum path sum including this node as the root
        int maxPathThroughRoot = root->data + leftSum + rightSum;

        // Update the global result if this path has the highest sum
        res = max(res, maxPathThroughRoot);

        // Return the maximum path sum for the current subtree
        return root->data + max(leftSum, rightSum);
    }

    int findMaxSum(Node *root) {
        int res = INT_MIN; // Initialize with a very small value
        maxPathSumUtil(root, res);
        return res;
    }
};
