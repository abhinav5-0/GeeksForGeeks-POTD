## Maximum Sum of Elements Not Part of LIS

**Difficulty:** Medium  
**Accuracy:** 48.67%  
**Submissions:** 16K+  
**Points:** 4

---

### 🧾 Problem Statement

Given an array `arr[]` of positive integers, your task is to find the **maximum possible sum of all elements that are *not* part of the Longest Increasing Subsequence (LIS)**.

---

### 🧠 Examples

#### Example 1
**Input:**  
`arr[] = [4, 6, 1, 2, 3, 8]`  
**Output:**  
`10`  
**Explanation:**  
LIS = `[1, 2, 3, 8]`  
Elements not in LIS = `[4, 6]` → Sum = `10`

#### Example 2
**Input:**  
`arr[] = [5, 4, 3, 2, 1]`  
**Output:**  
`14`  
**Explanation:**  
LIS = `[1]`  
Elements not in LIS = `[5, 4, 3, 2]` → Sum = `14`

---

### 📌 Constraints
- `1 ≤ arr.size() ≤ 10^3`
- `1 ≤ arr[i] ≤ 10^5`

---

### 🚀 Approach

1. Compute the total sum of the array.
2. Use a modified version of the **patience sorting** technique to find the **sum of elements in the LIS**.
3. Subtract the LIS sum from the total to get the final answer.

---

### ✅ Optimized C++ Solution

```cpp
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> dp, sums;
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        for (int x : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            int idx = it - dp.begin();

            if (it == dp.end()) {
                dp.push_back(x);
                sums.push_back((sums.empty() ? 0 : sums.back()) + x);
            } else {
                *it = x;
                sums[idx] = (idx ? sums[idx - 1] : 0) + x;
            }
        }

        return total - sums.back();
    }
};
```

---

### ⏱️ Time Complexity
- `O(N log N)` due to `lower_bound` operations for each element

---

### 🧩 Space Complexity
- `O(N)` for `dp[]` and `sums[]` vectors

---
