class Solution {
public:
    
    void dfs(Node* root, int k, vector<int>& path, int &count) {
        if(!root) return;
        
        path.push_back(root->data);
        
        int sum = 0;
        for(int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if(sum == k) count++;
        }
        
        dfs(root->left, k, path, count);
        dfs(root->right, k, path, count);
        
        path.pop_back();
    }
    
    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        
        dfs(root, k, path, count);
        
        return count;
    }
};
