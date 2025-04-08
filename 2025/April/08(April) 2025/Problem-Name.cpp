class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adj, visited);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Remove the edge (c, d) from the adjacency list
        auto it = find(adj[c].begin(), adj[c].end(), d);
        if (it != adj[c].end()) adj[c].erase(it);
        
        it = find(adj[d].begin(), adj[d].end(), c);
        if (it != adj[d].end()) adj[d].erase(it);

        // Check if d is still reachable from c
        vector<bool> visited(V, false);
        dfs(c, adj, visited);

        return !visited[d];  // if d is not visited, then edge (c,d) is a bridge
    }
};
