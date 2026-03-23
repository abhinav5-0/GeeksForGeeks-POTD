# Length of Longest Cycle in a Graph

## 🧠 Problem Statement

Given a directed graph with **V vertices (0 to V-1)** and **E edges**, where each edge is represented as:

```
edges[i] = [u, v]
```

This means there is a directed edge from **u → v**.

👉 Each node has **at most one outgoing edge**.

---

## 🎯 Objective

Find the **length of the longest cycle** in the graph.

* If a cycle exists → return its **length**
* If no cycle exists → return **-1**

---

## 🔁 What is a Cycle?

A cycle is a path that:

* Starts and ends at the same node
* All edges follow the given direction

---

## 📌 Example 1

```
Input:
V = 7
edges = [[0,5], [1,0], [2,4], [3,1], [4,6], [5,6], [6,3]]

Output:
5
```

### ✅ Explanation

Longest cycle is:

```
0 → 5 → 6 → 3 → 1 → 0
```

Length = **5**

---

## 📌 Example 2

```
Input:
V = 8
edges = [[0,1], [1,2], [2,3], [3,0], [4,1], [5,4], [6,2], [7,6]]

Output:
4
```

### ✅ Explanation

Longest cycle is:

```
0 → 1 → 2 → 3 → 0
```

Length = **4**

---

## ⚙️ Approach (DFS + Visitation Tracking)

### Key Idea:

* Use **DFS traversal**
* Track:

  * `visited[]` → node already processed
  * `pathVis[]` → node in current DFS path
  * `time[]` → step number when node visited

### Cycle Detection Logic:

* If we reach a node already in `pathVis`, a **cycle is found**
* Cycle length = `current_step - time[node]`

---

## ⏱️ Time & Space Complexity

* **Time:** O(V)
* **Space:** O(V)

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0), pathVis(V, 0), time(V, 0);
        int timer = 0, ans = -1;

        function<void(int)> dfs = [&](int node) {
            vis[node] = 1;
            pathVis[node] = 1;
            time[node] = timer++;

            for (auto &e : edges) {
                if (e[0] == node) {
                    int next = e[1];

                    if (!vis[next]) {
                        dfs(next);
                    } else if (pathVis[next]) {
                        ans = max(ans, time[node] - time[next] + 1);
                    }
                }
            }

            pathVis[node] = 0;
        };

        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i);
        }

        return ans;
    }
};
```

---

## ☕ Java Solution

```java
class Solution {
    public int longestCycle(int V, int[][] edges) {
        int[] vis = new int[V];
        int[] pathVis = new int[V];
        int[] time = new int[V];

        int[] ans = {-1};
        int[] timer = {0};

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                dfs(i, edges, vis, pathVis, time, timer, ans);
            }
        }

        return ans[0];
    }

    void dfs(int node, int[][] edges, int[] vis, int[] pathVis, int[] time, int[] timer, int[] ans) {
        vis[node] = 1;
        pathVis[node] = 1;
        time[node] = timer[0]++;

        for (int[] e : edges) {
            if (e[0] == node) {
                int next = e[1];

                if (vis[next] == 0) {
                    dfs(next, edges, vis, pathVis, time, timer, ans);
                } else if (pathVis[next] == 1) {
                    ans[0] = Math.max(ans[0], time[node] - time[next] + 1);
                }
            }
        }

        pathVis[node] = 0;
    }
}
```

---

## 🐍 Python Solution

```python
class Solution:
    def longestCycle(self, V, edges):
        vis = [0]*V
        pathVis = [0]*V
        time = [0]*V

        timer = 0
        ans = -1

        def dfs(node):
            nonlocal timer, ans

            vis[node] = 1
            pathVis[node] = 1
            time[node] = timer
            timer += 1

            for u, v in edges:
                if u == node:
                    if not vis[v]:
                        dfs(v)
                    elif pathVis[v]:
                        ans = max(ans, time[node] - time[v] + 1)

            pathVis[node] = 0

        for i in range(V):
            if not vis[i]:
                dfs(i)

        return ans
```

---

## 🚀 Optimization Tip

Since each node has **at most one outgoing edge**, you can optimize further using:

* Direct traversal instead of scanning all edges
* Use array like `next[node]`

This reduces complexity to strict **O(V)**.

---

## ✅ Summary

* Detect cycles using DFS + path tracking
* Use timestamps to calculate cycle length
* Return max cycle length or -1

---

✨ Happy Coding!
