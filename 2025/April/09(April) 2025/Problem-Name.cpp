class Solution {
  public:
    void dfs(int u, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, int& time) {
        disc[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (disc[v] == -1) { // If v is not visited
                children++;
                parent[v] = u;
                dfs(v, adj, disc, low, parent, ap, time);

                low[u] = min(low[u], low[v]);

                // Articulation point conditions
                if (parent[u] == -1 && children > 1)
                    ap[u] = true;
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }
            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> ap(V, false);
        int time = 0;

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1)
                dfs(i, adj, disc, low, parent, ap, time);
        }

        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (ap[i])
                result.push_back(i);
        }

        if (result.empty())
            return {-1};

        return result;
    }
};
