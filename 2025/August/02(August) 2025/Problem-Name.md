## Problem: Longest Subarray with Majority Greater than K

**Difficulty:** Medium  
**Points:** 4

### Description:
Given an array `arr[]` and an integer `k`, find the length of the **longest subarray** in which the **count of elements greater than `k`** is **more** than the **count of elements less than or equal to `k`**.

### Examples:

**Input:**  
`arr[] = [1, 2, 3, 4, 1], k = 2`  
**Output:** `3`  
**Explanation:** Subarrays like `[2, 3, 4]` or `[3, 4, 1]` satisfy the condition. No longer subarray does.

**Input:**  
`arr[] = [6, 5, 3, 4], k = 2`  
**Output:** `4`  
**Explanation:** All elements are > 2, so entire array is valid.

### Constraints:
- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`
- `0 ≤ k ≤ 10^6`

---

### Approach:
1. Convert each element:
   - `+1` if `arr[i] > k`
   - `-1` if `arr[i] <= k`

2. Maintain a **prefix sum** and use a hashmap to store the **first occurrence** of each prefix sum.

3. Key Observations:
   - If `prefixSum > 0`, the subarray from index `0` to `i` is valid.
   - Else, check if `prefixSum - 1` was seen before, meaning there was a previous point where a net positive balance was achieved.

4. Track the **maximum length** of such subarrays.

---

### Code:
```cpp
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> prefixIndex;
        int prefixSum = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            // Convert to +1 / -1
            if (arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1;

            // Case: sum is positive from start
            if (prefixSum > 0) {
                maxLen = i + 1;
            } 
            // Check if we have seen prefixSum - 1
            else {
                if (prefixIndex.find(prefixSum - 1) != prefixIndex.end()) {
                    maxLen = max(maxLen, i - prefixIndex[prefixSum - 1]);
                }
            }

            // Store first occurrence of this prefixSum
            if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
                prefixIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
```

---

### Time & Space Complexity:
- **Time:** `O(n)`  
- **Space:** `O(n)` (for the hashmap)

---

### Tags:
`prefix sum`, `hashing`, `greedy`, `sliding window`, `array`
