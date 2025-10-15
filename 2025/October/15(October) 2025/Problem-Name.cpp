class Solution {
  public:
    int count = 0; // to count nodes
    int ans = -1;  // to store result

    void inorder(Node* root, int k) {
        if (!root || ans != -1) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            ans = root->data;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(Node *root, int k) {
        inorder(root, k);
        return ans;
    }
};
