# Minimum Operations to Connect Hospitals

## Problem Summary

You are given `V` hospitals (nodes) and `E` undirected connections (edges). Each edge connects two hospitals. In **one operation**, you can remove any existing link and reconnect it between two hospitals that are currently in **different components**.

Your goal is to determine the **minimum number of operations** required to make the entire network connected.

If it is **not possible** to connect all hospitals into a single network, return `-1`.

---

## Key Concepts

To connect `V` nodes into a single connected component, you need at least:

```
V - 1 edges
```

If the number of edges `E < V - 1`, it is **impossible** to make the graph connected, even with rearrangements.

---

## Approach

### Step 1: Check if the number of edges is enough

```text
if E < V - 1 → return -1
```

### Step 2: Count the number of connected components

Use **Disjoint Set Union (DSU)** also known as **Union-Find**.

Let the number of connected components be `C`.

To connect `C` components, the minimum operations required are:

```
C - 1
```

---

## Algorithm

1. Initialize DSU with `V` nodes.
2. Union all given edges.
3. Count unique parents → number of connected components `C`.
4. If `E < V - 1`, return `-1`.
5. Otherwise, return `C - 1`.

---

## C++ Code

```cpp
class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        int E = edges.size();

        // If not enough edges to connect all hospitals
        if (E < V - 1) return -1;

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        // Count components using DSU
        for (auto& e : edges) {
            unite(e[0], e[1], parent, rank);
        }

        int components = 0;
        for (int i = 0; i < V; i++) {
            if (find(i, parent) == i)
                components++;
        }

        // Operations needed = number of components - 1
        return components - 1;
    }
};
```

---

## Time & Space Complexity

* **Time Complexity:** `O(V + E α(V))` where α is the inverse Ackermann function.
* **Space Complexity:** `O(V)`

---

## Example

### Input:

```
V = 4
edges = [[0,1], [0,2], [1,2]]
```

### Output:

```
1
```

Because components = 2 → operations = 1.

---

### Final Answer:

Minimum operations required = **C - 1**, only if `E >= V - 1`. Otherwise, return `-1`.
