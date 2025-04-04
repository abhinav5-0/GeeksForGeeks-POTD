# 🚀 Problem of the Day: Undirected Graph Cycle Detection

**Difficulty:** Medium  
**Accuracy:** 30.13%  
**Submissions:** 543K+  
**Average Time:** 20 mins  
**Points:** 4

---

## 🧩 Problem Statement

Given an **undirected graph** with `V` vertices and `E` edges, represented as a 2D vector `edges[][]`, where each entry `edges[i] = [u, v]` denotes an edge between vertices `u` and `v`, determine whether the graph contains a **cycle** or not.

---

## 📥 Input

- `V`: Number of vertices (1 ≤ V ≤ 10⁵)
- `edges[][]`: A list of E pairs `[u, v]` representing undirected edges (1 ≤ E ≤ 10⁵)

---

## 📤 Output

- Return `true` if the graph contains a **cycle**, otherwise return `false`.

---

## 🧪 Examples

### Example 1:



---

## ✅ Approach: Union-Find (Disjoint Set)

We use the **Disjoint Set Union (DSU)** data structure to detect cycles.

### Core Idea:
- For every edge `[u, v]`, check if `u` and `v` belong to the same set.
  - If **yes**, a cycle is detected.
  - If **no**, **union** the sets.

### Optimizations:
- **Path Compression** in `find()` function.
- **Union by Rank** to keep tree shallow.

---

## 💻 C++ Code (Using Union-Find)

```cpp
class Solution {
  public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V, 0);

        for (int i = 0; i < V; ++i)
            parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (!unionSet(u, v))
                return true;
        }

        return false;
    }
};
