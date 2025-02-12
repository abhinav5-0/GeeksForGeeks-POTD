class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        stack<Node*> st;
        Node* curr = root;
        int count = 0;
        
        while (!st.empty() || curr != NULL) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;  // Move to leftmost node
            }
            
            curr = st.top();
            st.pop();
            
            count++;
            if (count == k) return curr->data;  // Found the k-th smallest element
            
            curr = curr->right;  // Move to right subtree
        }
        
        return -1;  // If k is larger than the number of nodes
    }
};
