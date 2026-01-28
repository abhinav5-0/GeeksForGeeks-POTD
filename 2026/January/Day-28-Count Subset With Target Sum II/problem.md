# Count Subset With Target Sum II

**Difficulty:** Medium
**Accuracy:** 43.16%

---

## Problem Statement

Given an array `arr[]` of integers and an integer `k`, find the **count of subsets** whose sum is exactly equal to `k`.

> **Note:** It is guaranteed that the number of valid subsets fits in a 32-bit integer.

---

## Examples

### Example 1

**Input:**
`arr = [1, 3, 2], k = 3`

**Output:**
`2`

**Explanation:**
Valid subsets are `[1, 2]` and `[3]`.

---

### Example 2

**Input:**
`arr = [4, 2, 3, 1, 2], k = 4`

**Output:**
`3`

**Explanation:**
Valid subsets are `[4]`, `[2, 2]`, and `[3, 1]`.

---

### Example 3

**Input:**
`arr = [10, 20, 30], k = 25`

**Output:**
`0`

**Explanation:**
No subset exists with sum equal to `k`.

---

## Constraints

* `1 ≤ arr.size() ≤ 40`
* `-10^7 ≤ arr[i], k ≤ 10^7`

---

## Approach (Meet in the Middle)

Since `n ≤ 40`, generating all subsets directly (`2^40`) is infeasible.

We use **Meet in the Middle**:

1. Split the array into two halves.
2. Generate all possible subset sums of the **left half** and store their frequencies.
3. Generate all subset sums of the **right half**.
4. For each right sum `s`, count how many times `(k - s)` exists in the left sums.
5. Add them to the answer.

This reduces complexity to approximately `O(2^(n/2))`.

---

## Algorithm

1. Divide array into two halves `L` and `R`.
2. Generate all subset sums of `L` and store in a map.
3. Generate all subset sums of `R`.
4. For each sum `x` in `R`, add `freq[k - x]` from left map.
5. Return total count.

---

## Time & Space Complexity

* **Time:** `O(2^(n/2))`
* **Space:** `O(2^(n/2))`

---

## C++ Implementation

```cpp
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        int mid = n / 2;
        
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());
        
        unordered_map<long long, int> freq;
        
        // All subset sums of left half
        for (int mask = 0; mask < (1 << left.size()); mask++) {
            long long sum = 0;
            for (int i = 0; i < left.size(); i++) {
                if (mask & (1 << i)) sum += left[i];
            }
            freq[sum]++;
        }
        
        int ans = 0;
        
        // All subset sums of right half
        for (int mask = 0; mask < (1 << right.size()); mask++) {
            long long sum = 0;
            for (int i = 0; i < right.size(); i++) {
                if (mask & (1 << i)) sum += right[i];
            }
            if (freq.count(k - sum)) {
                ans += freq[k - sum];
            }
        }
        
        return ans;
    }
};
```

---

## Key Notes

* Handles **negative numbers** correctly.
* Much faster than classic DP for this constraint.
* Standard and expected solution for `n ≤ 40`.

---

If you want, I can also add **Python / Java versions** or a **dry run** section.
