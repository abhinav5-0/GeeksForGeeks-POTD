class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> result;
        int idx = 0;
        findLeaves(preorder, idx, INT_MIN, INT_MAX, result);
        return result;
    }

  private:
    void findLeaves(vector<int>& preorder, int& idx, int minVal, int maxVal, vector<int>& result) {
        if (idx >= preorder.size() || preorder[idx] < minVal || preorder[idx] > maxVal)
            return;

        int root = preorder[idx++];
        int currentIdx = idx;

        // Left Subtree
        findLeaves(preorder, idx, minVal, root - 1, result);
        // Right Subtree
        findLeaves(preorder, idx, root + 1, maxVal, result);

        // If no child was added, it's a leaf
        if (currentIdx == idx)
            result.push_back(root);
    }
};
