## Bellman-Ford Shortest Path Algorithm

### Problem Statement
Given a weighted directed graph with `V` vertices numbered from `0` to `V-1` and `E` edges, represented by a 2D array `edges[][]`, where `edges[i] = [u, v, w]` represents a directed edge from node `u` to node `v` with weight `w`, and a source vertex `src`, compute the shortest distances from the source to all other vertices.

If a vertex is unreachable from the source, its distance should be marked as `108`. If the graph contains a negative weight cycle, return `[-1]` to indicate that shortest paths cannot be reliably computed.

### Input
- Integer `V`: Number of vertices (1 ≤ V ≤ 100)
- 2D vector `edges` of size E: Each element is a triplet `[u, v, w]` where:
  - `u`: Source vertex of the edge
  - `v`: Destination vertex of the edge
  - `w`: Weight of the edge (-1000 ≤ w ≤ 1000)
- Integer `src`: Source vertex (0 ≤ src < V)

### Output
- Vector of integers where the `i-th` element represents the shortest distance from `src` to vertex `i`
- If a vertex is unreachable, its distance should be `108`
- If the graph contains a negative weight cycle, return `[-1]`

### Examples
**Example 1:**
```text
Input: V = 5, edges = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
Output: [0, 5, 6, 6, 7]
```
**Explanation:**
- 0 -> 1 has distance 5
- 0 -> 1 -> 2 has distance 6
- 0 -> 1 -> 2 -> 4 -> 3 has distance 6
- 0 -> 1 -> 2 -> 4 has distance 7

**Example 2:**
```text
Input: V = 4, edges = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
Output: [-1]
```
**Explanation:**
- Graph contains a negative weight cycle: 1 → 2 → 3 → 1

### Constraints
- 1 ≤ V ≤ 100
- 1 ≤ E ≤ V*(V-1)
- -1000 ≤ w ≤ 1000
- 0 ≤ src < V

### Algorithm: Bellman-Ford
1. Initialize distance array `dist` with value `1e8` (representing unreachable) for all vertices except `src`, which is set to `0`.
2. Repeat `V-1` times:
   - For each edge `(u, v, w)`, update `dist[v]` if `dist[u] + w < dist[v]`
3. Check for negative weight cycles by verifying if any distance can still be updated.
4. If yes, return `[-1]`, else return `dist`.

### Time Complexity
- **O(V * E)** — Each edge is relaxed `V-1` times.

### Space Complexity
- **O(V)** — To store distance array.

### Code (C++)
```cpp
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

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

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};
