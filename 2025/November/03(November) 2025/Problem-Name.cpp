class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> revGraph(V);
        vector<int> indegree(V, 0);

        // Step 1: Reverse the graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            revGraph[v].push_back(u);
            indegree[u]++;
        }

        // Step 2: Queue for Kahn’s algorithm
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 3: BFS Topological Sort
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int adj : revGraph[node]) {
                indegree[adj]--;
                if (indegree[adj] == 0)
                    q.push(adj);
            }
        }

        // Step 4: Sort safe nodes
        sort(safe.begin(), safe.end());
        return safe;
    }
};
