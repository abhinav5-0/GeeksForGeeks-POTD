class Solution {
public:
    int res = 0;
    int dfs(int u, int p, vector<vector<int>>& adj) {
        int m1 = 0, m2 = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int d = dfs(v, u, adj) + 1;
                if (d > m1) m2 = m1, m1 = d;
                else if (d > m2) m2 = d;
            }
        }
        res = max(res, m1 + m2);
        return m1;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, adj);
        return res;
    }
};
