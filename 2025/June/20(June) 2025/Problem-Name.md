# Problem: Group Balls by Sequence

**Difficulty:** Medium
**Accuracy:** 41.62%
**Submissions:** 9K+
**Points:** 4

## Problem Statement

You are given an array `arr[]` of positive integers, where each element `arr[i]` represents the number written on the i-th ball, and a positive integer `k`.

Your task is to determine whether it is possible to rearrange all the balls into groups such that:

* Each group contains exactly `k` balls.
* The numbers in each group are consecutive integers.

## Examples

### Example 1:

**Input:**
`arr[] = [10, 1, 2, 11]`, `k = 2`
**Output:**
`true`
**Explanation:**
The hand can be rearranged as `[1, 2]`, `[10, 11]`. There are two groups of size 2. Each group has 2 consecutive numbers.

### Example 2:

**Input:**
`arr[] = [7, 8, 9, 10, 11]`, `k = 2`
**Output:**
`false`
**Explanation:**
The hand cannot be rearranged into groups of 2, since there are 5 cards, and 5 cannot be divided into groups of 2.

## Constraints

* `1 <= arr.size() <= 10^6`
* `0 <= arr[i] <= 10^5`
* `1 <= k <= 10^3`

## Function Signature

```cpp
class Solution {
  public:
    bool validgroup(vector<int> &arr, int k);
};
```

## Notes

* Use a frequency map to count occurrences of each number.
* Try to form groups starting from the smallest number available.
* If at any point a group of consecutive numbers of length `k` can't be formed, return `false`.
* If all elements are used correctly, return `true`.
