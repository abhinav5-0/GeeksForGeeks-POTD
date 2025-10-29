## Graph Diameter

**Difficulty:** Medium
**Accuracy:** 73.97%
**Points:** 4

### Problem Statement

You are given an undirected connected graph with `V` vertices numbered from `0` to `V-1` and `E` edges, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` represents an undirected edge between vertex `u` and vertex `v`.

Find the **diameter** of the graph.

> The diameter of a graph (sometimes called the width) is the number of edges on the longest path between two vertices in the graph.

**Note:** The graph does not contain any cycles (i.e., it's a tree).

---

### Examples

**Input:**
`V = 6, E = 5`
`edges = [[0, 1], [0, 4], [1, 3], [1, 2], [2, 5]]`

**Output:**
`4`

**Explanation:**
The longest path in the graph is from vertex `4` to vertex `5` → (4 → 0 → 1 → 2 → 5).

---

**Input:**
`V = 7, E = 6`
`edges = [[0, 2], [0, 4], [0, 3], [3, 1], [3, 5], [1, 6]]`

**Output:**
`4`

**Explanation:**
The longest path in the graph is from vertex `2` to vertex `6` → (2 → 0 → 3 → 1 → 6).

---

### Constraints

* 2 ≤ V ≤ 10^5
* 1 ≤ E ≤ V - 1
* 0 ≤ edges[i][0], edges[i][1] < V

---

### Approach

We can find the **diameter of a tree** using **two BFS traversals**:

1. Pick any node and run BFS to find the farthest node `A`.
2. Run BFS again starting from `A` to find the farthest node `B`.
3. The distance between `A` and `B` is the **diameter** of the graph.

This works efficiently because the longest path in a tree always lies between two leaf nodes.

**Time Complexity:** O(V + E)
**Space Complexity:** O(V)

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Helper function to perform BFS and return farthest node + distance
    pair<int, int> bfs(int start, vector<int> adj[]) {
        vector<int> dist(adj->size(), -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nbr : adj[node]) {
                if (dist[nbr] == -1) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                    if (dist[nbr] > dist[farthestNode])
                        farthestNode = nbr;
                }
            }
        }
        return {farthestNode, dist[farthestNode]};
    }

    int diameter(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        // Build adjacency list
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 1: BFS from any node (say 0)
        pair<int, int> first = bfs(0, adj);

        // Step 2: BFS from farthest node found
        pair<int, int> second = bfs(first.first, adj);

        // The distance in the second BFS is the diameter
        return second.second;
    }
};

// Example usage
int main() {
    Solution obj;
    vector<vector<int>> edges1 = {{0,1},{0,4},{1,3},{1,2},{2,5}};
    cout << obj.diameter(6, edges1) << endl; // Output: 4

    vector<vector<int>> edges2 = {{0,2},{0,4},{0,3},{3,1},{3,5},{1,6}};
    cout << obj.diameter(7, edges2) << endl; // Output: 4
}
```

---

### Explanation

* The first BFS finds one endpoint (`A`) of the longest path.
* The second BFS from `A` finds the opposite endpoint (`B`).
* The number of edges between `A` and `B` = **Diameter** of the graph.

---

### Example Walkthrough

For `edges = [[0, 1], [0, 4], [1, 3], [1, 2], [2, 5]]`:

1. BFS from `0` → farthest node = `5`.
2. BFS from `5` → farthest node = `4`, distance = 4.
   Hence, **diameter = 4**.

---

### Key Insight

This two-phase BFS (or DFS) technique is a classic and efficient way to compute the diameter of any tree-like graph.
