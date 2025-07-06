# Maximum Sum Combination

**Difficulty:** Medium
**Accuracy:** 49.69%
**Submissions:** 91K+
**Points:** 4
**Average Time:** 30 minutes

---

## Problem Statement

You are given two integer arrays `a[]` and `b[]` of equal size. A **sum combination** is formed by adding one element from `a[]` and one from `b[]`, using each index pair `(i, j)` at most once. Your task is to return the **top k maximum sum combinations**, sorted in non-increasing order.

---

## Input Format

* Two integer arrays `a[]` and `b[]`, both of size `n`
* An integer `k`

---

## Output Format

* A list of `k` integers representing the top `k` maximum sum combinations.

---

## Constraints

* `1 <= a.size() = b.size() <= 10^5`
* `1 <= k <= a.size()`
* `1 <= a[i], b[i] <= 10^4`

---

## Examples

### Example 1:

**Input:**

```
a[] = [3, 2]
b[] = [1, 4]
k = 2
```

**Output:**

```
[7, 6]
```

**Explanation:**
All combinations:

* 3 + 1 = 4
* 3 + 4 = 7
* 2 + 1 = 3
* 2 + 4 = 6
  Top 2 sums are: **7 and 6**

---

### Example 2:

**Input:**

```
a[] = [1, 4, 2, 3]
b[] = [2, 5, 1, 6]
k = 3
```

**Output:**

```
[10, 9, 9]
```

**Explanation:**
Top 3 combinations:

* 4 + 6 = 10
* 3 + 6 = 9
* 4 + 5 = 9

---

## Approach

* Sort both arrays in descending order.
* Use a max heap (priority queue) to get the largest sum combinations efficiently.
* Use a set to track visited pairs to avoid duplicate computations.
* Push new candidate pairs into the heap using indices `(i+1, j)` and `(i, j+1)`.
* Repeat until you collect `k` maximum sums.

---

## Time Complexity

* Sorting: `O(n log n)`
* Heap operations: `O(k log k)`

---

## Space Complexity

* Heap and visited set take up to `O(k)` space.
