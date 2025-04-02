class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> result;  // To store BFS traversal
        int V = adj.size();  // Number of vertices
        vector<bool> visited(V, false); // Visited array
        queue<int> q;        // Queue for BFS

        // Start BFS from vertex 0
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            // Traverse all adjacent nodes of the current node
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return result;
    }
};
