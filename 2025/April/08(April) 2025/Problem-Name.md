### 📘 Bridge Edge in Graph - Problem of the Day

#### 🔍 Problem Statement
Given an undirected graph with `V` vertices (numbered from `0` to `V-1`) and `E` edges, determine whether a specific edge `(c, d)` is a **bridge**.

An edge is called a bridge if **removing it increases the number of connected components** in the graph.

#### ✅ Constraints
- `1 ≤ V, E ≤ 10^5`
- `0 ≤ c, d ≤ V-1`

#### 📄 Examples

**Input 1:**
```text
c = 1, d = 2
```
**Output:**
```text
true
```
Explanation: Removing edge (1, 2) disconnects the graph.

**Input 2:**
```text
c = 0, d = 2
```
**Output:**
```text
false
```
Explanation: Removing edge (0, 2) does not disconnect the graph.

---

## 🔧 Approach

1. Build the adjacency list of the graph.
2. Temporarily remove the edge `(c, d)`.
3. Perform a Depth-First Search (DFS) starting from node `c`.
4. If `d` is still reachable → edge is **not** a bridge.
5. If `d` is **not reachable** → edge **is** a bridge.

---

## 🧠 C++ Code

```cpp
class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, adj, visited);
            }
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Remove edge (c, d)
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

        vector<bool> visited(V, false);
        dfs(c, adj, visited);

        return !visited[d];
    }
};
```

---

## 🔮 Sample Usage

### Input:
```text
V = 5, E = 5
Edges = [ [0,1], [1,2], [2,0], [1,3], [3,4] ]
c = 1, d = 2
```

### Output:
```text
true
```

---

Let us know if you want the Python version, explanation visuals, or test cases!

