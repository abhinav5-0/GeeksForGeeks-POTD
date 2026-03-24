# Course Schedule I

## 🧠 Problem Statement

You are given `n` courses, labeled from `0` to `n - 1`, and a list of prerequisite pairs `prerequisites[][]`.

Each pair `[x, y]` indicates that you must complete course `y` before taking course `x`.

Your task is to determine whether it is possible to finish all courses.

Return:

* `true` → if all courses can be completed
* `false` → if it is impossible (due to a cycle)

---

## 📌 Key Idea

This problem is equivalent to detecting a **cycle in a directed graph**.

* Courses → Nodes
* Prerequisites → Directed edges
* If a cycle exists → Not possible to finish all courses

---

## 🔍 Examples

### Example 1

```
Input:
n = 4
prerequisites = [[2, 0], [2, 1], [3, 2]]

Output:
true
```

**Explanation:**

* Course 2 depends on 0 and 1
* Course 3 depends on 2
* Valid order: `[0, 1, 2, 3]` or `[1, 0, 2, 3]`

---

### Example 2

```
Input:
n = 3
prerequisites = [[0, 1], [1, 2], [2, 0]]

Output:
false
```

**Explanation:**

* Cycle exists: `0 → 1 → 2 → 0`
* Impossible to complete all courses

---

## ⚙️ Approach (Topological Sort - Kahn’s Algorithm)

1. Create adjacency list
2. Compute indegree of each node
3. Push nodes with indegree `0` into queue
4. Process nodes:

   * Remove node
   * Reduce indegree of neighbors
   * Push new `0` indegree nodes
5. If processed nodes == `n` → return `true`

---

## ⏱️ Complexity

* Time: `O(V + E)`
* Space: `O(V + E)`

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(int neigh : adj[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        return count == n;
    }
};
```

---

## ☕ Java Solution

```java
class Solution {
    public boolean canFinish(int n, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++) adj.add(new ArrayList<>());
        
        int[] indegree = new int[n];
        
        for(int[] p : prerequisites) {
            adj.get(p[1]).add(p[0]);
            indegree[p[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.add(i);
        }
        
        int count = 0;
        
        while(!q.isEmpty()) {
            int node = q.poll();
            count++;
            
            for(int neigh : adj.get(node)) {
                indegree[neigh]--;
                if(indegree[neigh] == 0)
                    q.add(neigh);
            }
        }
        
        return count == n;
    }
}
```

---

## 🐍 Python Solution

```python
from collections import deque

def canFinish(n, prerequisites):
    adj = [[] for _ in range(n)]
    indegree = [0] * n
    
    for x, y in prerequisites:
        adj[y].append(x)
        indegree[x] += 1
    
    q = deque()
    for i in range(n):
        if indegree[i] == 0:
            q.append(i)
    
    count = 0
    
    while q:
        node = q.popleft()
        count += 1
        
        for neigh in adj[node]:
            indegree[neigh] -= 1
            if indegree[neigh] == 0:
                q.append(neigh)
    
    return count == n
```

---

## 🚀 Summary

* Detect cycle in directed graph
* Use Topological Sort (BFS)
* If all nodes processed → possible
* Else → cycle exists ❌
