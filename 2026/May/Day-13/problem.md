# Mother Vertex

## Problem Statement

Given a directed graph with `V` vertices labeled from `0` to `V-1` and a list of edges `edges[][]`, where each edge is represented as `[u, v]` indicating a directed edge from vertex `u` to vertex `v`, find a **Mother Vertex** of the graph.

A **Mother Vertex** is a vertex from which all other vertices can be reached.

* If multiple such vertices exist, return the one with the **smallest value**.
* If no such vertex exists, return `-1`.

---

## Examples

### Example 1

**Input:**

```text
V = 5
edges[][] = [[0,2],[0,3],[1,0],[2,1],[3,4]]
```

**Output:**

```text
0
```

**Explanation:**
Vertices `0`, `1`, and `2` can reach all other vertices.
Among them, `0` is the smallest, so the answer is `0`.

---

### Example 2

**Input:**

```text
V = 3
edges[][] = [[0,1],[2,1]]
```

**Output:**

```text
-1
```

**Explanation:**
No vertex can reach all other vertices.
Hence, no Mother Vertex exists.

---

# Approach

## Key Observation

If we perform DFS traversal for all unvisited nodes, the **last finished vertex** can be a potential Mother Vertex.

Why?

* A Mother Vertex can reach every other node.
* Therefore, DFS starting from it finishes last.

After finding the candidate:

1. Reset visited array.
2. Run DFS from the candidate.
3. If all nodes become visited, candidate is the Mother Vertex.
4. Otherwise return `-1`.

---

# Algorithm

1. Create adjacency list.
2. Perform DFS for every unvisited node.
3. Store the last node from which DFS was started as candidate.
4. Reset visited array.
5. Run DFS from candidate.
6. If all vertices are visited → return candidate.
7. Else return `-1`.

---

# C++ Solution

```cpp
class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(V, 0);

        int candidate = -1;

        // Find candidate mother vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                candidate = i;
            }
        }

        // Reset visited array
        fill(visited.begin(), visited.end(), 0);

        // Verify candidate
        dfs(candidate, adj, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1;
            }
        }

        return candidate;
    }
};
```

---

# Dry Run

## Input

```text
V = 5
edges = [[0,2],[0,3],[1,0],[2,1],[3,4]]
```

## Adjacency List

```text
0 → 2, 3
1 → 0
2 → 1
3 → 4
4 →
```

## DFS Traversal

* Start DFS from `0`
* Reach all nodes: `0 → 2 → 1` and `0 → 3 → 4`
* Last candidate becomes `0`

## Verification

DFS from `0` visits all vertices.
Hence answer = `0`

---

# Time Complexity

```text
O(V + E)
```

* DFS traversal takes `O(V + E)`
* Verification DFS also takes `O(V + E)`

Overall complexity remains linear.

---

# Space Complexity

```text
O(V + E)
```

* Adjacency list stores edges.
* Visited array stores traversal state.
* Recursive DFS stack may take up to `O(V)`.

---

# Important Interview Points

* Mother Vertex exists only in directed graphs.
* The last finished DFS node is a strong candidate.
* Always verify the candidate using another DFS.
* This approach is based on DFS finishing order.
