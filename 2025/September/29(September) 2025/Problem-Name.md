# Maximum Subarray Sum 2

**Difficulty:** Hard  
**Accuracy:** 63.33%  
**Points:** 8  

---

## Problem Statement
You are given an array `arr[]` of integers and two integers `a` and `b`. You have to find the maximum possible sum of a contiguous subarray whose length is **at least `a`** and **at most `b`**.

---

## Examples

**Input:**
```text
arr = [4, 5, -1, -2, 6], a = 2, b = 4
```
**Output:**
```text
9
```
**Explanation:** The subarray `[4, 5]` has length 2 and sum 9, which is the maximum among all subarrays of length between 2 and 4.

---

**Input:**
```text
arr = [-1, 3, -1, -2, 5, 3, -5, 2, 2], a = 3, b = 5
```
**Output:**
```text
8
```
**Explanation:** The subarray `[3, -1, -2, 5, 3]` has length 5 and sum 8, which is the maximum among all subarrays of length between 3 and 5.

---

## Constraints
- `1 ≤ arr.size() ≤ 10^5`
- `-10^5 ≤ arr[i] ≤ 10^5`
- `1 ≤ a ≤ b ≤ arr.size()`

---

## Approach
1. Compute prefix sums: `pref[i] = arr[0] + arr[1] + ... + arr[i-1]` (with `pref[0] = 0`).
2. For a subarray `(l..r)`, the sum is:
   ```
   sum(l, r) = pref[r+1] - pref[l]
   ```
3. We want subarray length between `a` and `b`, meaning:
   ```
   r - l + 1 ∈ [a, b]
   → l ∈ [r-b+1, r-a+1]
   ```
4. Maintain a deque to keep track of the **minimum prefix sum** in the valid range of `l`.
5. For each `r`, calculate:
   ```
   maxSum = max(maxSum, pref[r+1] - minPrefInRange)
   ```

This ensures `O(n)` time complexity.

---

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + arr[i];
        }

        deque<int> dq; // store indices of prefix sums
        long long ans = LLONG_MIN;

        for (int r = 0; r < n; r++) {
            // Add new left index for subarray length >= a
            if (r - a + 1 >= 0) {
                int idx = r - a + 1;
                // maintain increasing order of pref values
                while (!dq.empty() && pref[dq.back()] >= pref[idx]) 
                    dq.pop_back();
                dq.push_back(idx);
            }

            // Remove indices that are too far (length > b)
            while (!dq.empty() && dq.front() < r - b + 1) {
                dq.pop_front();
            }

            // If we have valid left index, calculate max sum
            if (!dq.empty()) {
                ans = max(ans, pref[r+1] - pref[dq.front()]);
            }
        }

        return (int)ans;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** `O(n)` (each index is pushed and popped at most once from deque).
- **Space Complexity:** `O(n)` for prefix sum array and deque.

---
