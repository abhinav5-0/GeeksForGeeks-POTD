## Problem: K Closest Elements

**Difficulty:** Medium
**Accuracy:** 15.96%
**Submissions:** 82K+
**Points:** 4
**Average Time:** 30m

### Problem Statement:

You are given a sorted array `arr[]` of unique integers, an integer `k`, and a target value `x`. Return exactly `k` elements from the array closest to `x`, excluding `x` if it exists.

An element `a` is considered closer to `x` than element `b` if:

1. $|a - x| < |b - x|$, or
2. $|a - x| == |b - x|$ and `a > b` (i.e., prefer the larger element if tied)

Return the `k` closest elements in **order of closeness**.

### Examples:

**Input:**
`arr[] = [1, 3, 4, 10, 12]`, `k = 2`, `x = 4`
**Output:** `3 1`
**Explanation:** 4 is excluded. Closest elements to 4 are: 3 (diff 1), 1 (diff 3). So, the 2 closest elements are: 3 and 1.

**Input:**
`arr[] = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56]`, `k = 4`, `x = 35`
**Output:** `39 30 42 45`
**Explanation:** 35 is excluded. First closest element is 39 (diff 4), then 30 (diff 5), then 42 (diff 7), and 45 (diff 10).

### Constraints:

* 1 ≤ arr.size() ≤ 10^5
* 1 ≤ k ≤ arr.size()
* 1 ≤ x ≤ 10^6
* 1 ≤ arr\[i] ≤ 10^6

### Function Signature:

```cpp
class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x);
};
```

### Expected Output:

Return a vector of `k` closest elements in the order of closeness.
