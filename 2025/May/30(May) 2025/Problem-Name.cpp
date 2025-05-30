/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;  // -1 to handle if no such element exists
        while (root != NULL) {
            if (root->data <= k) {
                ans = root->data;        // this could be the answer
                root = root->right;      // try to find a bigger value <= k
            } else {
                root = root->left;       // go left to find smaller values
            }
        }
        return ans;
    }
};
