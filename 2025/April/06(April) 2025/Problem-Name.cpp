class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V]; // Step 1: Create adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> indegree(V, 0); // Step 2: Compute indegree of all vertices
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i); // Step 3: Push nodes with indegree 0
            }
        }

        vector<int> topo;
        while (!q.empty()) { // Step 4: BFS traversal
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo;
    }
};
