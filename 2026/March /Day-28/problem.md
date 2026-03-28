# Articulation Point - II

## Problem Statement

You are given an **undirected graph** with **V vertices** and **E edges**. The graph is represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` indicates an undirected edge between vertices `u` and `v`.

Your task is to return all the **articulation points** (or cut vertices) in the graph.

### Definition

An **articulation point** is a vertex which, when removed (along with all its connected edges), **increases the number of connected components** in the graph.

### Notes

* The graph may be **disconnected**.
* If no articulation point exists, return `[-1]`.

---

## Examples

### Example 1

```
Input:
V = 5
edges[][] = [[0,1], [1,4], [4,3], [4,2], [2,3]]

Output:
[1, 4]
```

**Explanation:**
Removing vertex `1` or `4` disconnects the graph.

---

### Example 2

```
Input:
V = 4
edges[][] = [[0,1], [1,0], [0,2]]

Output:
[0]
```

**Explanation:**
Removing vertex `0` increases the number of connected components.

---

## Constraints

* `1 ≤ V, E ≤ 10^4`

---

## Approach (Tarjan’s Algorithm)

We use **DFS (Depth First Search)** along with two arrays:

* `tin[node]` → Time of first visit
* `low[node]` → Lowest reachable time

### Key Conditions

1. **Root Node Case**

   * If root has more than one child → articulation point

2. **Non-root Case**

   * If `low[child] >= tin[node]` → articulation point

---

## Algorithm Steps

1. Build adjacency list
2. Initialize:

   * `visited[]`
   * `tin[]`
   * `low[]`
3. Run DFS for each unvisited node
4. Track articulation points

---

## C++ Solution

```cpp
class Solution {
public:
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis,
             vector<int> &tin, vector<int> &low, vector<int> &mark, int &timer) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, mark, timer);
                low[node] = min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0), tin(V, -1), low(V, -1), mark(V, 0);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, mark, timer);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i]) ans.push_back(i);
        }

        if (ans.empty()) return {-1};
        return ans;
    }
};
```

---

## Java Solution

```java
class Solution {
    static int timer;

    public static void dfs(int node, int parent, ArrayList<ArrayList<Integer>> adj,
                           boolean[] vis, int[] tin, int[] low, boolean[] mark) {
        vis[node] = true;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (int it : adj.get(node)) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, adj, vis, tin, low, mark);
                low[node] = Math.min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = true;
                }
                child++;
            } else {
                low[node] = Math.min(low[node], tin[it]);
            }
        }

        if (parent == -1 && child > 1) {
            mark[node] = true;
        }
    }

    public ArrayList<Integer> articulationPoints(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        boolean[] vis = new boolean[V];
        int[] tin = new int[V];
        int[] low = new int[V];
        boolean[] mark = new boolean[V];

        timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (mark[i]) ans.add(i);
        }

        if (ans.size() == 0) {
            ans.add(-1);
        }
        return ans;
    }
}
```

---

## Python Solution

```python
class Solution:
    def articulationPoints(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        vis = [0] * V
        tin = [-1] * V
        low = [-1] * V
        mark = [0] * V
        timer = 0

        def dfs(node, parent):
            nonlocal timer
            vis[node] = 1
            tin[node] = low[node] = timer
            timer += 1
            child = 0

            for it in adj[node]:
                if it == parent:
                    continue
                if not vis[it]:
                    dfs(it, node)
                    low[node] = min(low[node], low[it])

                    if low[it] >= tin[node] and parent != -1:
                        mark[node] = 1
                    child += 1
                else:
                    low[node] = min(low[node], tin[it])

            if parent == -1 and child > 1:
                mark[node] = 1

        for i in range(V):
            if not vis[i]:
                dfs(i, -1)

        ans = [i for i in range(V) if mark[i]]
        return ans if ans else [-1]
```

---

## Complexity

* **Time Complexity:** `O(V + E)`
* **Space Complexity:** `O(V)`

---

## Summary

* Use DFS + Low Time (Tarjan’s Algorithm)
* Identify articulation points using conditions on `low[]` and `tin[]`
* Works efficiently for large graphs
