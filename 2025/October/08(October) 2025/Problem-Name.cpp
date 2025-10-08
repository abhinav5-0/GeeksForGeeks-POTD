class Solution {
  public:
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> postIndex; 
        for (int i = 0; i < post.size(); i++) {
            postIndex[post[i]] = i;
        }

        int preIndex = 0;
        return build(pre, post, postIndex, preIndex, 0, post.size() - 1);
    }

  private:
    Node* build(vector<int>& pre, vector<int>& post, unordered_map<int, int>& postIndex, 
                int& preIndex, int left, int right) {
        if (preIndex >= pre.size() || left > right)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        // If single node subtree
        if (left == right || preIndex >= pre.size())
            return root;

        // Find index of next preorder element in postorder
        int mid = postIndex[pre[preIndex]];

        // Build left and right subtrees
        root->left = build(pre, post, postIndex, preIndex, left, mid);
        root->right = build(pre, post, postIndex, preIndex, mid + 1, right - 1);

        return root;
    }
};
