# Number of Ways to Arrive at Destination

## 📝 Problem Statement

You are given an **undirected weighted graph** with `V` vertices (`0` to `V-1`) and `E` edges. Each edge is represented as:

```
[ui, vi, timei]
```

meaning an undirected edge between `ui` and `vi` which takes `timei` minutes.

Your task is to compute **how many different ways** you can reach from node `0` to node `V-1` in the **shortest possible time**.

---

## 🧠 Key Insight

This is a variation of **Dijkstra's Algorithm**:

* Compute **shortest distances** from node `0` to all nodes.
* Also maintain a `ways[]` array to count **number of shortest paths** to each node.

### Rules:

* If a **shorter path** is found → update distance + reset ways.
* If an **equal shortest path** is found → add ways.

---

## ✔️ Approach

1. Use adjacency list to represent graph.
2. Use Dijkstra's priority queue.
3. Maintain:

   * `dist[]` → shortest distance
   * `ways[]` → number of shortest paths
4. Return `ways[V-1]`.

---

## ⏱️ Time Complexity

```
O(E log V)
```

---

## ✅ C++ Code (Optimized)

```cpp
class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Dijkstra arrays
        vector<long long> dist(V, 1e18);
        vector<int> ways(V, 0);

        // Min heap: {dist, node}
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &p : adj[u]) {
                int v = p.first;
                long long wt = p.second;

                // Case 1: shorter path found
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }

                // Case 2: equal shortest path
                else if(dist[v] == dist[u] + wt) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[V-1];
    }
};
```

---

## 🎯 Example

### Input:

```
V = 4
edges = [[0,1,2], [1,2,3], [0,3,5], [1,3,3], [2,3,4]]
```

### Output:

```
2
```

Two ways to reach node 3 in shortest time (5):

* 0 → 3
* 0 → 1 → 3

---

If you want, I can also add a **dry run**, **graph visualization**, or **practice problems**!
