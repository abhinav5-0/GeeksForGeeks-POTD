# Smallest Range in K Lists

**Difficulty:** Hard
**Accuracy:** 43.21%
**Submissions:** 37K+
**Points:** 8
**Average Time:** 40 minutes

## Problem Statement

Given a 2D integer array `arr[][]` of size `k * n`, where each row is sorted in ascending order, find the smallest range `[l, r]` that includes at least one element from each of the `k` lists. If more than one such range exists, return the first one.

---

### Input

* An integer `n` representing the number of elements in each list.
* An integer `k` representing the number of lists.
* A 2D array `arr[k][n]` with each row sorted in ascending order.

### Output

* A list `[l, r]` representing the smallest range covering at least one element from each list.

---

### Constraints

* `1 <= k, n <= 500`
* `0 <= arr[i][j] <= 10^5`

---

### Examples

#### Example 1

**Input:**

```
n = 5, k = 3
arr = [[4, 7, 9, 12, 15],
       [0, 8, 10, 14, 20],
       [6, 12, 16, 30, 50]]
```

**Output:** `[6, 8]`
**Explanation:** Smallest range includes 6 from 3rd list, 7 from 1st list, and 8 from 2nd list.

#### Example 2

**Input:**

```
n = 5, k = 3
arr = [[1, 3, 5, 7, 9],
       [0, 2, 4, 6, 8],
       [2, 3, 5, 7, 11]]
```

**Output:** `[1, 2]`
**Explanation:** 1 from 1st list and 2 appears in both 2nd and 3rd list.

#### Example 3

**Input:**

```
n = 2, k = 3
arr = [[2, 4],
       [1, 7],
       [20, 40]]
```

**Output:** `[4, 20]`
**Explanation:** Smallest range includes 4 from 1st list, 7 from 2nd list, and 20 from 3rd list.

---

## Approach

* Use a min-heap to keep track of the minimum element among current elements from each list.
* Maintain a variable for the current maximum value.
* Continuously update the range `[min, max]` and replace the minimum element with the next element from the same list.
* Stop when any one of the lists is exhausted.

---

## Complexity

* **Time Complexity:** `O(n * k * log k)`
* **Space Complexity:** `O(k)`

---

## Tags

* Heap / Priority Queue
* Sliding Window
* Greedy
* Arrays
