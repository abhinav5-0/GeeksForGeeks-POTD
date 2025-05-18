class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);
        bool reverse = true;  // Start with right to left

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);
            
            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();

                // Position to fill the node data in result vector
                int index = reverse ? levelSize - 1 - i : i;
                level[index] = node->data;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Append current level nodes to result
            for (int val : level)
                result.push_back(val);

            // Flip the direction for next level
            reverse = !reverse;
        }

        return result;
    }
};
