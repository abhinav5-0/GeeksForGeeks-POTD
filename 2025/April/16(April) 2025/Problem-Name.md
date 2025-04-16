# Floyd-Warshall Algorithm - Problem Statement

## Difficulty
Medium

## Accuracy
32.89%

## Submissions
184K+

## Points
4

## Average Time
15 minutes

---

## Problem Description
You are given a weighted directed graph, represented by an adjacency matrix `dist[][]` of size `n x n`, where `dist[i][j]` represents the weight of the edge from node `i` to node `j`. If there is no direct edge, `dist[i][j]` is set to a large value (i.e., 10^8) to represent infinity.

The graph may contain negative edge weights, but it does **not** contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes `i` and `j` in the graph.

**Note:** Modify the distances for every pair in place.

---

## Input Format
- An integer `n`, the size of the matrix.
- A matrix `dist` of size `n x n`, where `dist[i][j]` is the weight of the edge from `i` to `j`.

---

## Output Format
- A matrix where each element `dist[i][j]` represents the shortest distance from node `i` to node `j`.

---

## Constraints
- `1 <= dist.size() <= 100`
- `-1000 <= dist[i][j] <= 1000`

---

## Example 1
**Input:**
```
dist[][] = [[0, 4, 108, 5, 108],
            [108, 0, 1, 108, 6],
            [2, 108, 0, 3, 108],
            [108, 108, 1, 0, 2],
            [1, 108, 108, 4, 0]]
```

**Output:**
```
[[0, 4, 5, 5, 7],
 [3, 0, 1, 4, 6],
 [2, 6, 0, 3, 5],
 [3, 7, 1, 0, 2],
 [1, 5, 5, 4, 0]]
```

## Example 2
**Input:**
```
dist[][] = [[0, -1, 2],
            [1, 0, 108],
            [3, 1, 0]]
```

**Output:**
```
[[0, -1, 2],
 [1, 0, 3],
 [2, 1, 0]]
```

---

## Explanation
Each cell `dist[i][j]` in the output shows the shortest distance from node `i` to node `j`, computed by considering all possible intermediate nodes.

Example: From node `2` to node `0`, the shortest distance is `2` by following path `2 -> 1 -> 0`. From `1` to `2`, the shortest distance is `3` by following path `1 -> 0 -> 2`.

---

## Solution Approach (Floyd-Warshall Algorithm)
For each node `k` from `0` to `n-1`:
- For each pair of nodes `(i, j)`:
  - Update `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])` if `dist[i][k]` and `dist[k][j]` are not infinity (i.e., 10^8).

This algorithm has a time complexity of **O(n^3)** and is suitable for `n <= 100`.

