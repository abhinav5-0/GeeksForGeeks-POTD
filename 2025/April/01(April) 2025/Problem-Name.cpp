class Solution {
  public:
    void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, adj, visited, result);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> result;
        int V = adj.size();
        vector<bool> visited(V, false);
        
        dfsUtil(0, adj, visited, result);
        
        return result;
    }
};
