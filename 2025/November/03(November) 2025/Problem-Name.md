## Safe States

**Difficulty:** Medium
**Accuracy:** 55.52%
**Points:** 4
**Average Time:** 20m

### Problem Statement

Given a directed graph with `V` vertices numbered from `0` to `V-1` and `E` directed edges, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` represents a directed edge from vertex `u` to vertex `v`. Return all **Safe Nodes** of the graph.

A vertex with no outgoing edges is called a **terminal node**. A vertex is considered **safe** if every path starting from it eventually reaches a terminal node.

---

### Example 1

**Input:**
`V = 5, E = 6`
`edges = [[1,0], [1,2], [1,3], [1,4], [2,3], [3,4]]`

**Output:**
`[0, 1, 2, 3, 4]`

**Explanation:**
`0` and `4` are terminal nodes. All paths from `1, 2, 3` lead to terminal nodes, hence all are safe.

---

### Example 2

**Input:**
`V = 4, E = 3`
`edges = [[1,2], [2,3], [3,2]]`

**Output:**
`[0]`

**Explanation:**
`0` is the only terminal node, and no other node leads to it.

---

### Constraints

* `1 ≤ V ≤ 10^5`
* `0 ≤ E ≤ 10^5`
* `0 ≤ edges[i][0], edges[i][1] < V`

---

### Approach (Using Topological Sorting on Reversed Graph)

1. **Reverse the Graph:**
   For each directed edge `u → v`, create a reversed edge `v → u`. This helps in identifying which nodes lead to terminal nodes.

2. **Compute Indegree:**
   Count the number of incoming edges (indegree) for every node in the reversed graph.

3. **Apply Kahn's Algorithm:**

   * Push all nodes with indegree `0` (i.e., terminal nodes in the original graph) into a queue.
   * Process nodes in BFS order, reducing indegree for adjacent nodes.
   * If a node’s indegree becomes `0`, it’s safe.

4. **Sort and Return Safe Nodes:**
   Collect all safe nodes and return them in sorted order.

---

### C++ Code Implementation

```cpp
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
```

---

### Complexity Analysis

* **Time Complexity:** `O(V + E)`
* **Space Complexity:** `O(V + E)`

---

### Key Insight

By reversing the graph and applying topological sorting, we can efficiently determine which nodes eventually lead to terminal nodes, classifying them as **safe states**.
