class Solution {
  public:
    int moves = 0;
    
    int dfs(Node* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        moves += abs(left) + abs(right);
        
        // Net balance of candies for this node
        return root->data + left + right - 1;
    }
    
    int distCandy(Node* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
};
