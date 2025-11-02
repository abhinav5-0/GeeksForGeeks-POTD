class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        // Step 2: Compute indegree for topological sort
        vector<int> indeg(V, 0);
        for (auto &e : edges) {
            indeg[e[1]]++;
        }

        // Step 3: Kahn's algorithm for Topological Sort
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);
            for (int nxt : adj[node]) {
                indeg[nxt]--;
                if (indeg[nxt] == 0)
                    q.push(nxt);
            }
        }

        // Step 4: Create adjacency matrix for quick edge lookup
        vector<vector<bool>> hasEdge(V, vector<bool>(V, false));
        for (auto &e : edges)
            hasEdge[e[0]][e[1]] = true;

        // Step 5: Count possible new edges
        int count = 0;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int u = topo[i], v = topo[j];
                if (!hasEdge[u][v]) count++;
            }
        }

        return count;
    }
};
