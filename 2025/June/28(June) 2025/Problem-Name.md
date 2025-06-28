# Problem: Counting Elements in Two Arrays

**Difficulty:** Medium
**Accuracy:** 37.12%
**Submissions:** 91K+
**Points:** 4
**Average Time:** 20m

## Problem Statement

You are given two unsorted arrays `a[]` and `b[]`. Both arrays may contain duplicate elements. For each element in `a[]`, your task is to count how many elements in `b[]` are less than or equal to that element.

### Input

* Two integer arrays `a[]` and `b[]`

### Output

* Return a list of integers where each value represents the count of elements in `b[]` less than or equal to the corresponding element in `a[]`.

### Examples

#### Example 1

```
Input:
a[] = [4, 8, 7, 5, 1]
b[] = [4, 48, 3, 0, 1, 1, 5]

Output:
[5, 6, 6, 6, 3]

Explanation:
For a[0] = 4, there are 5 elements in b (4, 3, 0, 1, 1) that are ≤ 4.
For a[1] = 8 and a[2] = 7, there are 6 elements in b that are ≤ 8 and ≤ 7.
For a[3] = 5, there are 6 elements in b that are ≤ 5.
For a[4] = 1, there are 3 elements in b (0, 1, 1) that are ≤ 1.
```

#### Example 2

```
Input:
a[] = [10, 20]
b[] = [30, 40, 50]

Output:
[0, 0]

Explanation:
There are no elements in b[] that are ≤ 10 or ≤ 20. Hence, the output is [0, 0].
```

### Constraints

* 1 ≤ a.size(), b.size() ≤ 10^5
* 0 ≤ a\[i], b\[j] ≤ 10^5

### Function Signature

```cpp
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b);
};
```

### Expected Time Complexity

* `O(n log n + m log n)` where `n` is the size of `b` and `m` is the size of `a`.

### Expected Space Complexity

* `O(1)` (excluding the space for the output vector)
