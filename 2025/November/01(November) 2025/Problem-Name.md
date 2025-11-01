### Course Schedule II

**Difficulty:** Medium
**Accuracy:** 51.77%
**Points:** 4
**Average Time:** 25m

---

### 🧩 Problem Statement

You are given **n** courses, labeled from **0 to n - 1**, and a 2D array `prerequisites[][]` where `prerequisites[i] = [x, y]` indicates that you need to take course **y** first if you want to take course **x**.

Find the ordering of courses we should take to complete all the courses.

There may be multiple correct orders — return any one of them. If it is impossible to finish all tasks, return an empty array.
The Driver code will print `true` if you return any correct order of courses else it will print `false`.

---

### 🧠 Examples

**Input:**
`n = 3, prerequisites = [[1, 0], [2, 1]]`
**Output:** `true`
**Explanation:**
To take course 1, you must finish course 0. To take course 2, you must finish course 1. So the only valid order is `[0, 1, 2]`.

**Input:**
`n = 4, prerequisites = [[2, 0], [2, 1], [3, 2]]`
**Output:** `true`
**Explanation:**
Course 2 requires both 0 and 1. Course 3 requires course 2. Hence, both `[0, 1, 2, 3]` and `[1, 0, 2, 3]` are valid.

---

### 📋 Constraints

* 1 ≤ n ≤ 10⁴
* 0 ≤ prerequisites.size() ≤ 10⁵
* 0 ≤ prerequisites[i][0], prerequisites[i][1] < n
* All prerequisite pairs are unique
* `prerequisites[i][0] ≠ prerequisites[i][1]`

---

### 💡 Approach — Topological Sort (Kahn’s Algorithm)

This is a **topological sorting** problem on a **Directed Acyclic Graph (DAG)**.

#### Steps:

1. Build an adjacency list representing the graph.
2. Maintain an array `indegree[]` where `indegree[i]` counts how many prerequisites a course has.
3. Push all courses with indegree `0` into a queue (no prerequisites).
4. Repeatedly remove nodes from the queue, add them to the result, and decrease the indegree of their dependent courses.
5. If all courses are processed, return the result; otherwise, return an empty list (cycle detected).

---

### 💻 C++ Solution

```cpp
class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        // Build adjacency list and indegree count
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        if (order.size() == n)
            return order;

        return {};
    }
};
```

---

### 🧮 Complexity Analysis

* **Time Complexity:** O(V + E) — every node and edge is processed once.
* **Space Complexity:** O(V + E) — adjacency list + indegree array + queue.

---

### ✅ Summary

| Concept         | Description                                 |
| --------------- | ------------------------------------------- |
| Algorithm       | Topological Sort (Kahn’s Algorithm)         |
| Problem Type    | Directed Acyclic Graph (DAG)                |
| Handles Cycles? | Yes — returns empty array if cycle detected |
| Output          | Any valid order of courses                  |
