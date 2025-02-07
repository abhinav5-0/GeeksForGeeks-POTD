class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    
  private:
    void inorderTraversal(Node* root, vector<int>& result) {
        if (root == NULL) return;
        
        // Traverse left subtree
        inorderTraversal(root->left, result);
        
        // Visit node
        result.push_back(root->data);
        
        // Traverse right subtree
        inorderTraversal(root->right, result);
    }
};
