class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                // Find position to fill in level vector
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->data;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Add current level to final result
            for (int val : level)
                result.push_back(val);
            
            // Toggle direction
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};
