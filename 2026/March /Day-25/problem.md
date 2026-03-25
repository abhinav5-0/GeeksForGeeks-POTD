# Minimum Height Roots

## Problem Statement

You are given an undirected graph with **V vertices** numbered from `0` to `V-1` and **E edges**, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` represents an edge from vertex `u` to `v`.

You can choose any vertex as the root of the tree. Your task is to find all the vertices that, when chosen as the root, result in the **minimum possible height** of the tree.

> **Note:** The height of a rooted tree is the number of edges on the path from the root to any leaf node.

---

## Examples

### Example 1

**Input:**
`V = 5, E = 4`
`edges = [[0,1], [1,2], [1,3], [3,4]]`

**Output:**
`[2, 3]`

**Explanation:**
If we choose vertices `2` or `3` as the root, the resulting tree has the minimum possible height, which is `2`.

---

### Example 2

**Input:**
`V = 4, E = 3`
`edges = [[0,1], [0,2], [0,3]]`

**Output:**
`[0]`

**Explanation:**
Only vertex `0` gives the minimum possible height, which is `1`.

---

## Constraints

* `1 ≤ V ≤ 10^5`
* `0 ≤ E = V - 1`
* `0 ≤ edges[i][0], edges[i][1] < V`

---

## Approach (Optimal - Topological Trimming / BFS)

This problem is solved using the concept of **tree centers**.

### Key Idea

* Minimum height trees are rooted at the **center(s)** of the tree.
* A tree can have **1 or 2 centers**.

### Steps

1. Build adjacency list.
2. Compute degree of each node.
3. Push all **leaf nodes (degree = 1)** into a queue.
4. Remove leaves level by level.
5. Continue until ≤ 2 nodes remain.
6. These remaining nodes are the answer.

---

## Time & Space Complexity

* **Time:** `O(V)`
* **Space:** `O(V)`

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> minHeightRoots(int V, vector<vector<int>>& edges) {
        if (V == 1) return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        int remaining = V;

        while (remaining > 2) {
            int size = q.size();
            remaining -= size;

            while (size--) {
                int node = q.front(); q.pop();

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};
```

---

## Java Solution

```java
import java.util.*;

class Solution {
    public List<Integer> minHeightRoots(int V, int[][] edges) {
        if (V == 1) return Arrays.asList(0);

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        int[] degree = new int[V];

        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1)
                q.offer(i);
        }

        int remaining = V;

        while (remaining > 2) {
            int size = q.size();
            remaining -= size;

            while (size-- > 0) {
                int node = q.poll();

                for (int neighbor : adj.get(node)) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                        q.offer(neighbor);
                }
            }
        }

        return new ArrayList<>(q);
    }
}
```

---

## Python Solution

```python
from collections import deque

class Solution:
    def minHeightRoots(self, V, edges):
        if V == 1:
            return [0]

        adj = [[] for _ in range(V)]
        degree = [0] * V

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            degree[u] += 1
            degree[v] += 1

        q = deque()
        for i in range(V):
            if degree[i] == 1:
                q.append(i)

        remaining = V

        while remaining > 2:
            size = len(q)
            remaining -= size

            for _ in range(size):
                node = q.popleft()
                for neighbor in adj[node]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        q.append(neighbor)

        return list(q)
```

---

## Summary

* This is a **graph + BFS problem**.
* Core idea: **Trim leaves until center(s) remain**.
* Final nodes are roots of **Minimum Height Trees (MHTs)**.
