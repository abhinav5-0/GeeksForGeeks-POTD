# Number of Submatrix Having Sum X

## Difficulty: Hard

**Accuracy:** 74.23%
**Submissions:** 9K+
**Points:** 8

---

## Problem Statement

Given a matrix `mat[][]` of size `n x m` and an integer `x`, find the number of **square submatrices** whose **sum of elements is equal to `x`**.

---

## Example 1

### Input:

```
mat[][] = [
  [2, 4, 7, 8, 10],
  [3, 1, 1, 1, 1],
  [9, 11, 1, 2, 1],
  [12, -17, 1, 1, 1]
]
x = 10
```

### Output:

```
3
```

### Explanation:

There are 3 square submatrices whose sum of elements equals 10.

---

## Example 2

### Input:

```
mat[][] = [
  [3, 3, 5, 3],
  [2, 2, 2, 6],
  [11, 2, 2, 4]
]
x = 1
```

### Output:

```
0
```

### Explanation:

There is no square submatrix whose sum of elements equals 1.

---

## Constraints

* `1 ≤ n, m ≤ 100`
* `-10^3 ≤ mat[i][j] ≤ 10^3`
* `-10^9 ≤ x ≤ 10^9`

---

## Function Signature (C++)

```cpp
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x);
};
```

---

## Notes

* Only **square** submatrices are allowed (k x k size).
* Brute force approach may work due to constraints, but optimized solution using **prefix sum (2D prefix sum)** is recommended.
* Time complexity target: **O(n² × m²)** or optimized further using prefix sums.

---

**End of Problem**
