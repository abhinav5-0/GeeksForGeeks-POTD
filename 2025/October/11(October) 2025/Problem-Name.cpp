class Solution {
  public:
    int maxSum; // global variable to store the result

    int helper(Node* root) {
        if (!root) return 0;

        // recursively find max path sum for left and right subtrees
        int left = max(0, helper(root->left));   // ignore negative paths
        int right = max(0, helper(root->right));

        // compute the path sum passing through this node
        int currentSum = left + right + root->data;

        // update global max if current path is greater
        maxSum = max(maxSum, currentSum);

        // return the max path sum including this node and one of its subtrees
        return root->data + max(left, right);
    }

    int findMaxSum(Node *root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }
};
