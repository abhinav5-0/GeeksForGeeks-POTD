class Solution {
  public:
    pair<int, int> solve(Node* root) {
        if (!root) return {0, 0};

        // Recurse on left and right children
        auto left = solve(root->left);
        auto right = solve(root->right);

        // If we include current node
        int include = root->data + left.second + right.second;

        // If we exclude current node
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }

    int getMaxSum(Node* root) {
        auto res = solve(root);
        return max(res.first, res.second);
    }
};
