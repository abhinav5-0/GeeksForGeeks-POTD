# Count the Paths in a Directed Acyclic Graph (DAG)

## Problem Statement

Given a **Directed Acyclic Graph (DAG)** with `V` nodes labeled from `0` to `V-1`, and a list of directed edges, count the total number of **distinct paths** from a given **start node** to a **destination node**.

Each edge is represented as `edges[i] = [u, v]`, indicating a directed edge from `u` to `v`.

---

## Input

* `edges[][]`: A list of directed edges.
* `V`: Total number of vertices.
* `src`: Source node.
* `dest`: Destination node.

---

## Output

* Return the total number of **distinct paths** from `src` to `dest`.

---

## Examples

### Example 1:

```text
Input:
edges = [[0,1], [0,3], [2,0], [2,1], [1,3]]
V = 4
src = 2
dest = 3

Output:
3

Explanation:
There are three distinct paths from 2 to 3:
1. 2 -> 1 -> 3
2. 2 -> 0 -> 3
3. 2 -> 0 -> 1 -> 3
```

### Example 2:

```text
Input:
edges = [[0,1], [1,2], [1,3], [2,3]]
V = 4
src = 0
dest = 3

Output:
2

Explanation:
There are two distinct paths from 0 to 3:
1. 0 -> 1 -> 2 -> 3
2. 0 -> 1 -> 3
```

---

## Constraints

* 2 ≤ V ≤ 10^3
* 1 ≤ E = edges.size() ≤ (V \* (V - 1)) / 2

---

## Solution

```cpp
class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V); // Adjacency list

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        int count = 0;

        // DFS function
        function<void(int)> dfs = [&](int node) {
            if (node == dest) {
                count++;
                return;
            }

            for (int neighbor : adj[node]) {
                dfs(neighbor);
            }
        };

        dfs(src);

        return count;
    }
};
```

---

## Notes

* This problem is efficiently solved using DFS because the graph is a DAG (no cycles).
* Use of recursion and backtracking allows exploring all possible paths from `src` to `dest`.
* The adjacency list is used for efficient representation and traversal of the graph.
