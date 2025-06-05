class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V); // adjacency list

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        int count = 0;

        // DFS function
        function<void(int)> dfs = [&](int node) {
            if (node == dest) {
                count++;
                return;
            }

            for (int neighbor : adj[node]) {
                dfs(neighbor);
            }
        };

        dfs(src);

        return count;
    }
};
