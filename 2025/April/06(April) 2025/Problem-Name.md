# Topological Sort - Directed Acyclic Graph (DAG)

## 🧠 Problem Statement

Given a Directed Acyclic Graph (DAG) with `V` vertices (numbered from `0` to `V-1`) and a list of `E` directed edges, perform a topological sort.

Topological sorting is a linear ordering of vertices such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering.

> **Note:** If the returned topological sort is correct (i.e., maintains the ordering rule), it is accepted even if there are multiple valid orders.

---

## 📅 Input

- `V`: Number of vertices (2 ≤ V ≤ 10³)
- `E`: Number of edges (1 ≤ E ≤ V*(V-1)/2)
- `edges[][]`: A list where each element is a pair `[u, v]` representing a directed edge from vertex `u` to `v`.

---

## 📄 Output

- A list of integers representing a valid topological sort of the graph.

---

## 🔀 Example

### Input:
```
V = 6  
edges = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]
```

### Output:
```
true
```

### Explanation:
Valid topological orders include:
- `[4, 5, 0, 1, 2, 3]`
- `[5, 2, 4, 0, 1, 3]`
- and many more...

---

## 🛠️ Solution - Kahn's Algorithm (BFS-based)

### Steps:
1. Build an adjacency list from the edge list.
2. Calculate the indegree for each vertex.
3. Push all vertices with indegree `0` into a queue.
4. While the queue is not empty:
   - Pop a vertex, add it to the result.
   - Reduce the indegree of its neighbors.
   - If a neighbor’s indegree becomes `0`, add it to the queue.

---

## 💻 Code

```cpp
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo;
    }
};
```

---

## 🧪 Time & Space Complexity

- **Time Complexity:** `O(V + E)`  
- **Space Complexity:** `O(V + E)` (Adjacency list + Indegree array + Queue)

---

## ✅ Validity Check

The driver code includes a `check()` function to validate whether the output maintains the topological order condition.

---

## 📚 References

- [Topological Sort - GeeksForGeeks](https://www.geeksforgeeks.org/topological-sorting/)
- [Kahn’s Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm)

