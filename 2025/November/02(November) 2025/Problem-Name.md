## Max DAG Edges

**Difficulty:** Medium
**Accuracy:** 73.45%
**Points:** 4

### Problem Statement

Given a directed acyclic graph (DAG) with **V** vertices numbered from 0 to V-1 and **E** edges, represented as a 2D array `edges[][]`, where each entry `edges[i] = [u, v]` denotes a directed edge from vertex **u** to vertex **v**, find the maximum number of additional edges that can be added to the graph without forming any cycles.

**Note:** The resulting graph must remain a DAG, meaning that adding any further edge would not create a cycle.

---

### Examples

**Input:**
V = 3, E = 2, edges = [[0, 1], [1, 2]]
**Output:**
1
**Explanation:** The given DAG allows one more edge, 0 -> 2, which keeps the structure acyclic.

**Input:**
V = 4, E = 4, edges = [[0, 1], [0, 2], [1, 2], [2, 3]]
**Output:**
2
**Explanation:** Two additional edges (0 -> 3, 1 -> 3) can be added without forming cycles.

---

### Approach

1. **Topological Sorting:**

   * Perform a topological sort of the DAG using Kahn's Algorithm.
   * In a DAG, every edge goes from an earlier vertex to a later one in this order.

2. **Edge Possibility Check:**

   * For each pair `(i, j)` in the topological order (where `i` comes before `j`):

     * If an edge `i -> j` does **not** already exist, we can safely add it.
   * Count all such possible edges.

3. **Return the count.**

---

### Time and Space Complexity

* **Time Complexity:** O(V²) — checking all pairs of nodes.
* **Space Complexity:** O(V²) — adjacency matrix for quick edge lookup.

Given V ≤ 1000, this approach is efficient.

---

### C++ Implementation

```cpp
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

        // Step 3: Perform Kahn's algorithm for Topological Sort
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
```

---

### Example Walkthrough

**Example 1:**

```
V = 3, edges = [[0,1], [1,2]]
Topological order: [0,1,2]
Existing edges: 0->1, 1->2
Possible: (0->2)
Answer = 1
```

**Example 2:**

```
V = 4, edges = [[0,1], [0,2], [1,2], [2,3]]
Topological order: [0,1,2,3]
Existing edges: 0->1, 0->2, 1->2, 2->3
Possible: (0->3), (1->3)
Answer = 2
```

---

### ✅ Final Answer

This algorithm efficiently finds the **maximum number of additional edges** that can be added to a DAG while ensuring it remains acyclic.
