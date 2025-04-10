# Minimum Cost to Connect All Houses in a City

## Problem Statement
Given a 2D array `houses[][]`, consisting of `n` 2D coordinates `{x, y}` where each coordinate represents the location of a house, the task is to find the **minimum cost to connect all houses** in the city.

The cost of connecting two houses is the **Manhattan Distance** between the two points:
```
Manhattan Distance = |xi - xj| + |yi - yj|
```
where |p| denotes the absolute value of p.

---

## Constraints
- 1 ≤ n ≤ 10^3
- 0 ≤ houses[i][j] ≤ 10^3

---

## Input Format
- Integer `n`: the number of houses
- 2D array `houses[][]`: a list of n pairs [x, y]

---

## Output Format
- Integer representing the **minimum total cost** to connect all houses

---

## Examples

### Example 1:
**Input:**
```
n = 5
houses = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
```
**Output:**
```
105
```
**Explanation:**
- Connect (0, 7) and (0, 9) → cost = 2
- Connect (0, 7) and (20, 7) → cost = 20
- Connect (20, 7) and (30, 7) → cost = 10
- Connect (30, 7) and (40, 70) → cost = 73
- Total = 2 + 20 + 10 + 73 = 105

### Example 2:
**Input:**
```
n = 4
houses = [[0, 0], [1, 1], [1, 3], [3, 0]]
```
**Output:**
```
7
```
**Explanation:**
- (0,0) to (1,1) = 2
- (1,1) to (1,3) = 2
- (0,0) to (3,0) = 3
- Total = 2 + 2 + 3 = 7

---

## Approach
This is a classic **Minimum Spanning Tree (MST)** problem where:
- Each house is a node.
- Each connection is an edge weighted by Manhattan Distance.
- The goal is to connect all nodes with the **minimum total cost**.

### Algorithm Used: Prim's Algorithm
1. Use a min-heap to always pick the lowest cost edge.
2. Track visited houses to avoid cycles.
3. Accumulate the total cost of connecting all nodes.

### Time Complexity:
- O(n^2 log n), where n is the number of houses.

---

## C++ Code (Prim's Algorithm)
```cpp
class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0, 0)); // (cost, index)
        int totalCost = 0;

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int cost = top.first;
            int u = top.second;

            if (visited[u]) continue;

            visited[u] = true;
            totalCost += cost;

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    pq.push(make_pair(dist, v));
                }
            }
        }

        return totalCost;
    }
};
```

---

## Tags
- Graph
- Minimum Spanning Tree
- Prim's Algorithm
- Greedy
- Heap

