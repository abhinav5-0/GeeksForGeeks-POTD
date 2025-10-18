class Solution {
  public:
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    int findMedian(Node* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        
        if (n % 2 == 1) {
            // Odd number of elements -> middle one
            return arr[n / 2];
        } else {
            // Even number of elements -> (n/2)th element (1-based)
            return arr[(n / 2) - 1];
        }
    }
};
