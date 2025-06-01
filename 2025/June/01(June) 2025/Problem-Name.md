# Count Pairs Sum in Matrices

**Difficulty:** Easy
**Accuracy:** 45.66%
**Submissions:** 49K+
**Points:** 2

## Problem Statement

Given two matrices `mat1[][]` and `mat2[][]` of size `n x n`, where the elements in each matrix are arranged in strictly ascending order. Specifically:

* Each row is sorted from left to right.
* The last element of a row is smaller than the first element of the next row.

You are given a target value `x`. Your task is to find and count all pairs `{a, b}` such that:

* `a` is from `mat1`
* `b` is from `mat2`
* `a + b == x`

## Input

* An integer `n`, the size of both square matrices.
* An integer `x`, the target sum.
* Two matrices `mat1[n][n]` and `mat2[n][n]`.

## Output

* An integer representing the count of valid pairs `{a, b}` such that `a + b == x`.

## Constraints

* `1 ≤ n ≤ 100`
* `1 ≤ x ≤ 10^5`
* `1 ≤ mat1[i][j], mat2[i][j] ≤ 10^5`

## Examples

### Example 1:

**Input:**

```
n = 3, x = 21
mat1 = [[1, 5, 6], [8, 10, 11], [15, 16, 18]]
mat2 = [[2, 4, 7], [9, 10, 12], [13, 16, 20]]
```

**Output:**

```
4
```

**Explanation:**
The pairs whose sum is 21 are: `(1, 20), (5, 16), (8, 13), (11, 10)`

### Example 2:

**Input:**

```
n = 2, x = 10
mat1 = [[1, 2], [3, 4]]
mat2 = [[4, 5], [6, 7]]
```

**Output:**

```
2
```

**Explanation:**
The pairs whose sum is 10 are: `(4, 6)` and `(3, 7)`

## Solution Outline

1. Flatten `mat2` into a set for O(1) lookups.
2. Iterate through every element in `mat1`.
3. For each element `a` in `mat1`, check if `x - a` exists in `mat2`.
4. Count such pairs.

## C++ Function Signature

```cpp
class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x);
};
```

## Sample Implementation (C++)

```cpp
class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        unordered_set<int> elementsInMat2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                elementsInMat2.insert(mat2[i][j]);
            }
        }

        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (elementsInMat2.find(x - mat1[i][j]) != elementsInMat2.end()) {
                    count++;
                }
            }
        }

        return count;
    }
};
```
