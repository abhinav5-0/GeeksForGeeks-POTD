class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (!root) return result;
        
        // map to store the last node data for each horizontal distance
        map<int, int> hdNodeMap;
        
        // queue to perform level order traversal
        queue<pair<Node*, int>> q;
        q.push({root, 0}); // root has horizontal distance 0
        
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            
            // overwrite the value for this horizontal distance
            hdNodeMap[hd] = node->data;
            
            // add left child with HD - 1
            if (node->left)
                q.push({node->left, hd - 1});
            
            // add right child with HD + 1
            if (node->right)
                q.push({node->right, hd + 1});
        }
        
        // extract the bottom view from the map
        for (auto &it : hdNodeMap)
            result.push_back(it.second);
        
        return result;
    }
};
