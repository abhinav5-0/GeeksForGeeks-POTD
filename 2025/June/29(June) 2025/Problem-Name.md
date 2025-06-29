# Split Array Largest Sum

**Difficulty:** Hard
**Accuracy:** 58.9%
**Submissions:** 56K+
**Points:** 8

---

## Problem Statement

You are given an array `arr[]` and an integer `k`. Your task is to divide the array into `k` contiguous subarrays such that the **maximum sum among these subarrays is minimized**. Return this minimum possible maximum sum.

---

## Examples

### Example 1:

**Input:**
`arr[] = [1, 2, 3, 4]`, `k = 3`
**Output:**
`4`
**Explanation:**
Optimal split is `[1, 2], [3], [4]`. Maximum sum among subarrays is `4`, which is the minimum possible with 3 splits.

### Example 2:

**Input:**
`arr[] = [1, 1, 2]`, `k = 2`
**Output:**
`2`
**Explanation:**
Splitting the array as `[1, 1]` and `[2]` is optimal. This results in a maximum sum subarray of `2`.

---

## Constraints

* `1 ≤ k ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^4`

---

## Function Signature (C++)

```cpp
class Solution {
  public:
    int splitArray(vector<int>& arr, int k);
};
```

---

## Approach

### Binary Search + Greedy

* Use **binary search** on the answer space:

  * `low = max(arr)`
  * `high = sum(arr)`
* For each midpoint, check if it is **possible** to split the array into `≤ k` subarrays where each has sum `≤ mid` using a **greedy** method.
* Return the **minimum value** for which the condition is satisfied.

### Time Complexity

* Binary search over the range of sum: `O(log(sum - max))`
* Each feasibility check: `O(n)`
* **Total:** `O(n * log(sum - max))`
