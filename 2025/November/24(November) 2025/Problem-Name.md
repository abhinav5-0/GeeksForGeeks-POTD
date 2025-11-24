# Second Best Minimum Spanning Tree

## Problem Statement

Given an undirected graph with **V** vertices numbered from **0 to V-1** and **E** edges represented by `edges[][]`, where each entry

```
[u, v, w]
```

represents an undirected edge between nodes **u** and **v** with weight **w**.

You must compute the **weight of the second best Minimum Spanning Tree (MST)**.

A **second best MST** is defined as:

> A spanning tree whose total weight is **strictly greater than** the MST weight but is **minimum** among all such trees.

If no strictly greater spanning tree exists, return **-1**.

---

## Example

### Input

```
V = 5, E = 7
edges = [
  [0, 1, 4],
  [0, 2, 3],
  [1, 2, 1],
  [1, 3, 5],
  [2, 4, 10],
  [2, 3, 7],
  [3, 4, 2]
]
```

### Output

```
12
```

### Input

```
V = 5, E = 4
edges = [
  [0, 1, 2],
  [1, 2, 3],
  [2, 3, 4],
  [3, 4, 5]
]
```

### Output

```
-1
```

---

## Approach

To compute the second best MST:

### **1. Build the MST using Kruskal’s Algorithm**

* Sort edges by weight
* Use DSU/Union-Find to build MST
* Track the total MST weight
* Track MST tree structure for LCA preprocessing

If MST cannot be formed → return `-1`.

### **2. Preprocess MST for LCA with Maximum Edge Tracking**

We need to answer queries of:

> What is the **maximum edge weight** on the path between two nodes **u** and **v** in the MST?

We use **Binary Lifting**:

* `up[k][v]` = 2^k parent of v
* `maxEdge[k][v]` = max edge weight on path from v to its 2^k parent
* Depth array for lifting

### **3. Try substituting each non-MST edge**

For every edge `(u, v, w)` **not in MST**:

* Adding it creates a cycle
* Remove the **maximum weight edge** on the u→v path in MST
* Compute new MST candidate weight:
  `newWeight = mstWeight + w - maxEdge(u, v)`
* Keep the smallest value > mstWeight

If none found → return `-1`.

---

## Final C++ Code

```cpp
class Solution {
public:

    vector<int> parent, rnk;

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if(rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }

    int secondMST(int V, vector<vector<int>> &edges) {

        parent.resize(V);
        rnk.assign(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;

        vector<array<int, 3>> ed;
        for(auto &e : edges) ed.push_back({e[2], e[0], e[1]});
        sort(ed.begin(), ed.end());

        vector<vector<pair<int, int>>> mst(V);

        int mstWeight = 0, usedEdges = 0;

        for(auto &e : ed){
            int w = e[0], u = e[1], v = e[2];
            if(unite(u, v)){
                mstWeight += w;
                usedEdges++;
                mst[u].push_back({v, w});
                mst[v].push_back({u, w});
            }
        }

        if(usedEdges != V - 1) return -1;

        const int LOG = 17;
        vector<vector<int>> up(LOG, vector<int>(V, -1));
        vector<vector<int>> mx(LOG, vector<int>(V, 0));
        vector<int> depth(V, 0);

        function<void(int,int,int)> dfs = [&](int u, int p, int w){
            up[0][u] = p;
            mx[0][u] = w;
            for(auto &x : mst[u]){
                int v = x.first, wt = x.second;
                if(v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u, wt);
            }
        };

        dfs(0, -1, 0);

        for(int k = 1; k < LOG; k++){
            for(int v = 0; v < V; v++){
                if(up[k-1][v] == -1) {
                    up[k][v] = -1;
                    mx[k][v] = mx[k-1][v];
                } else {
                    up[k][v] = up[k-1][ up[k-1][v] ];
                    mx[k][v] = max(mx[k-1][v], mx[k-1][ up[k-1][v] ]);
                }
            }
        }

        auto maxEdgeOnPath = [&](int u, int v){
            if(depth[u] < depth[v]) swap(u, v);
            int maxW = 0;

            int diff = depth[u] - depth[v];
            for(int k = 0; k < LOG; k++){
                if(diff & (1 << k)){
                    maxW = max(maxW, mx[k][u]);
                    u = up[k][u];
                }
            }

            if(u == v) return maxW;

            for(int k = LOG-1; k >= 0; k--){
                if(up[k][u] != up[k][v]){
                    maxW = max({maxW, mx[k][u], mx[k][v]});
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            maxW = max({maxW, mx[0][u], mx[0][v]});
            return maxW;
        };

        int ans = INT_MAX;

        parent.resize(V);
        rnk.assign(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;

        vector<bool> isMST(edges.size(), false);

        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        for(int i = 0; i < edges.size(); i++){
            if(unite(edges[i][0], edges[i][1])){
                isMST[i] = true;
            }
        }

        for(int i = 0; i < edges.size(); i++){
            if(isMST[i]) continue;

            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            int mxW = maxEdgeOnPath(u, v);

            if(mxW == w) continue;

            int newW = mstWeight + w - mxW;
            if(newW > mstWeight)
                ans = min(ans, newW);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
```
