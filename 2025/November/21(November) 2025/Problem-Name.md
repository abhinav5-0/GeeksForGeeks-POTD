# Shortest Path Using At Most One Curved Edge

## Problem Summary

You are given a connected, undirected graph with **V** vertices and **E double-edges**. Each edge between nodes **x** and **y** has:

* A **straight edge** of weight `w1`
* A **curved edge** of weight `w2`

You must travel from vertex **a** to vertex **b**, using any number of straight edges but **at most one curved edge**.

Goal: **Find the shortest possible path** from `a → b` under this constraint.
If no such path exists, return **-1**.

---

## Key Insight

We need shortest distances:

* From `a` to all nodes using **only straight edges**
* From `b` to all nodes using **only straight edges**

This is done using **Dijkstra's algorithm twice**.

Then, for every curved edge `(x, y, w1, w2)` we consider:

### Using the curved edge from x → y:

```
Cost = distA[x] + w2 + distB[y]
```

### Using the curved edge from y → x:

```
Cost = distA[y] + w2 + distB[x]
```

We take the minimum over all such possibilities.
Also check:

```
distA[b]   // path without any curved edges
```

---

## Algorithm

1. Build adjacency list using only straight edges `(w1)`.
2. Run Dijkstra from `a` → get `distA[]`.
3. Run Dijkstra from `b` → get `distB[]`.
4. Initialize answer = `distA[b]` (straight-only path).
5. For every curved edge, compute the two possible curved combinations.
6. Return the smallest valid distance.

---

## Time Complexity

* Dijkstra twice: **O(E log V)**
* Curved-edge checking: **O(E)**

Total fits within constraints for up to `10^6` nodes/edges.

---

## C++ Implementation

```cpp
class Solution {
public:
    const long long INF = 1e18;

    vector<long long> dijkstra(int V, int src, vector<vector<pair<int,int>>> &adj) {
        vector<long long> dist(V, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {

        vector<vector<pair<int,int>>> adj(V);

        // Build graph using only straight edges (w1)
        for (auto &e : edges) {
            int x = e[0], y = e[1], w1 = e[2];
            adj[x].push_back({y, w1});
            adj[y].push_back({x, w1});
        }

        // Run Dijkstra from a and b
        vector<long long> distA = dijkstra(V, a, adj);
        vector<long long> distB = dijkstra(V, b, adj);

        long long ans = distA[b];  // straight-edge path

        // Try using each curved edge once
        for (auto &e : edges) {
            int x = e[0], y = e[1], w2 = e[3];

            if (distA[x] < INF && distB[y] < INF)
                ans = min(ans, distA[x] + w2 + distB[y]);

            if (distA[y] < INF && distB[x] < INF)
                ans = min(ans, distA[y] + w2 + distB[x]);
        }

        return ans == INF ? -1 : (int)ans;
    }
};
```

---

## Example

### Input

```
V = 4, E = 4, a = 1, b = 3
edges = [[0,1,1,4], [0,2,2,4], [0,3,3,1], [1,3,6,5]]
```

### Output

```
2
```

### Explanation

Use:

```
1 → 0 (straight cost 1)
0 → 3 (curved cost 1)
Total = 2
```

---

## Final Notes

* Works efficiently for large graphs (up to 1 million nodes).
* Uses only **two Dijkstra runs + linear scan** over edges.
* Guaranteed to fit in 32-bit integer per problem statement.
