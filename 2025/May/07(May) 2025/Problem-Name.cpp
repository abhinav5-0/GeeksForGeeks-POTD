class Solution {
  public:
    void dfs(Node* node, vector<int>& path, vector<vector<int>>& result) {
        if (node == NULL)
            return;

        // Add current node to the path
        path.push_back(node->data);

        // If it's a leaf node, add the path to result
        if (node->left == NULL && node->right == NULL) {
            result.push_back(path);
        } else {
            // Recur for left and right subtree
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }
};
