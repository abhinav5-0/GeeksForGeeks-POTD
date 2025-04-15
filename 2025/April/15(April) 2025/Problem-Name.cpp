class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8); // initialize all distances as "infinity"
        dist[src] = 0;            // distance to source is 0
        
        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; ++i) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        // Check for negative weight cycles
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1}; // Negative cycle found
            }
        }
        
        return dist;
    }
};
