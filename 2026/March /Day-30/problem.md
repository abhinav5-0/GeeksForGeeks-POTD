# Minimum Cost to Connect All Houses in a City

## Problem Statement

Given a 2D array `houses[][]` consisting of coordinates `{x, y}` where each coordinate represents the **location of a house**, the task is to find the **minimum cost to connect all the houses**.

The cost of connecting two houses is the **Manhattan Distance** between them:

```
|x1 - x2| + |y1 - y2|
```

---

## Key Insight

This problem is a classic **Minimum Spanning Tree (MST)** problem where:

* Each house is a node
* The cost between nodes is Manhattan distance

We can solve it using:

* **Prim’s Algorithm** (preferred for dense graphs)
* **Kruskal’s Algorithm** (using DSU)

---

## Approach (Prim’s Algorithm)

1. Start from any house (e.g., index 0)
2. Maintain a **min-heap (priority queue)** to pick the smallest edge
3. Keep track of visited houses
4. Always pick the minimum cost edge connecting a visited house to an unvisited house
5. Repeat until all houses are connected

---

## Example 1

**Input:**

```
n = 5
houses = [[0,7], [0,9], [20,7], [30,7], [40,70]]
```

**Output:**

```
105
```

**Explanation:**

* Connect (0,7) → (0,9) = 2
* Connect (0,7) → (20,7) = 20
* Connect (20,7) → (30,7) = 10
* Connect (30,7) → (40,70) = 73

Total = **105**

---

## Example 2

**Input:**

```
n = 4
houses = [[0,0], [1,1], [1,3], [3,0]]
```

**Output:**

```
7
```

**Explanation:**

* Connect (0,0) → (1,1) = 2
* Connect (1,1) → (1,3) = 2
* Connect (0,0) → (3,0) = 3

Total = **7**

---

## Constraints

* `1 ≤ n ≤ 10^3`
* `0 ≤ houses[i][j] ≤ 10^3`

---

## Complexity

* **Time Complexity:** `O(n^2 log n)` (Prim’s with heap)
* **Space Complexity:** `O(n)`

---

## Tags

* Graph
* Minimum Spanning Tree
* Greedy
* Heap
