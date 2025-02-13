class Solution {
  public:
    bool findTarget(Node *root, int target) {
        unordered_set<int> seen;
        return inorder(root, target, seen);
    }
    
  private:
    bool inorder(Node* root, int target, unordered_set<int>& seen) {
        if (!root) return false;
        
        // Check if complement exists in the set
        if (seen.count(target - root->data)) return true;
        
        // Add current node's value to set
        seen.insert(root->data);
        
        // Recur for left and right subtrees
        return inorder(root->left, target, seen) || inorder(root->right, target, seen);
    }
};
