## Shortest Cycle

**Difficulty:** Hard
**Accuracy:** 73.05%
**Points:** 8

### Problem Statement

You are given an undirected graph with `V` vertices numbered from `0` to `V-1` and `E` edges, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` represents an undirected edge between vertex `u` and vertex `v`.

Find the **length of the shortest cycle** in the graph. If the graph does not contain any cycle, return `-1`.

A **cycle** is a path that starts and ends at the same vertex without repeating any edge or vertex (except the start/end vertex). The shortest cycle is the one with the minimum number of edges.

---

### Example 1

**Input:**
`V = 7, E = 8`
`edges = [[0,5],[0,6],[5,1],[6,1],[6,2],[2,3],[3,4],[1,4]]`

**Output:**
`4`

**Explanation:**
Possible cycles are:

* `0 → 5 → 1 → 6 → 0` (length = 4)
* `1 → 4 → 3 → 2 → 6 → 1` (length = 5)
  The smallest one is `0 → 5 → 1 → 6 → 0`, with length 4.

---

### Example 2

**Input:**
`V = 7, E = 9`
`edges = [[0,5],[0,6],[1,2],[1,4],[1,5],[1,6],[2,6],[2,3],[3,4]]`

**Output:**
`3`

**Explanation:**
Possible cycles include:

* `1 → 2 → 6 → 1` (length = 3)
* `1 → 2 → 3 → 4 → 1` (length = 4)
* `0 → 5 → 1 → 6 → 0` (length = 4)
  The smallest one is `1 → 2 → 6 → 1`, with length 3.

---

### Constraints

* `1 ≤ V ≤ 10^3`
* `0 ≤ E ≤ 10^3`
* `0 ≤ edges[i][0], edges[i][1] < V`

---

### Approach

We can use **Breadth-First Search (BFS)** from each vertex to find the shortest cycle:

1. Build an adjacency list from the edges.
2. For every vertex `src`:

   * Initialize `dist` and `parent` arrays.
   * Run BFS from `src`.
   * During BFS, if a visited node `v` is found that is **not the parent** of the current node, a cycle is detected.
   * Calculate the cycle length as `dist[u] + dist[v] + 1`.
3. Keep track of the **minimum cycle length** found.
4. Return `-1` if no cycle exists.

---

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int shortest = INT_MAX;

        // BFS from every node
        for (int src = 0; src < V; src++) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;

            dist[src] = 0;
            q.push(src);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {  // Not visited
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if (parent[u] != v) {
                        // Cycle detected
                        int cycle_len = dist[u] + dist[v] + 1;
                        shortest = min(shortest, cycle_len);
                    }
                }
            }
        }

        return (shortest == INT_MAX) ? -1 : shortest;
    }
};
```

---

### Example Test

```cpp
int main() {
    Solution sol;
    int V = 7;
    vector<vector<int>> edges = {{0,5},{0,6},{5,1},{6,1},{6,2},{2,3},{3,4},{1,4}};
    cout << sol.shortCycle(V, edges) << endl; // Output: 4
}
```

---

### Complexity Analysis

* **Time Complexity:** O(V × (V + E)) — BFS from each vertex.
* **Space Complexity:** O(V + E) — for adjacency list and BFS tracking.

---

### Key Insight

BFS ensures shortest paths in unweighted graphs. Thus, the **first detected cycle during BFS** will always correspond to the **shortest possible cycle** involving that source node.
