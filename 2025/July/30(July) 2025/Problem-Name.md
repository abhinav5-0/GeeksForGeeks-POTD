### Problem: Subarrays with Sum K

**Difficulty:** Medium  
**Accuracy:** 49.74%  
**Submissions:** 88K+  
**Points:** 4

---

### Problem Statement:

Given an unsorted array `arr[]` of integers, find the number of subarrays whose sum exactly equals a given number `k`.

---

### Examples:

**Input:**  
`arr[] = [10, 2, -2, -20, 10]`, `k = -10`  
**Output:** `3`  
**Explanation:** Subarrays: `arr[0...3]`, `arr[1...4]`, `arr[3...4]` have sum exactly equal to -10.

**Input:**  
`arr[] = [9, 4, 20, 3, 10, 5]`, `k = 33`  
**Output:** `2`  
**Explanation:** Subarrays: `arr[0...2]`, `arr[2...4]` have sum exactly equal to 33.

**Input:**  
`arr[] = [1, 3, 5]`, `k = 0`  
**Output:** `0`  
**Explanation:** No subarray with 0 sum.

---

### Constraints:
- `1 ≤ arr.size() ≤ 10^5`
- `-10^3 ≤ arr[i] ≤ 10^3`
- `-10^5 ≤ k ≤ 10^5`

---

### C++ Code:

```cpp
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int count = 0;
        int prefixSum = 0;

        // Initialize with prefixSum 0 to handle case when subarray starts at index 0
        prefixSumCount[0] = 1;

        for (int num : arr) {
            prefixSum += num;

            // Check if (prefixSum - k) has occurred before
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }

            // Increment frequency of the current prefixSum
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};
```

---

### Time Complexity:
- **O(n)** — Single pass through the array.
- **O(n)** — For hashmap storage in the worst case.

---

### Space Complexity:
- **O(n)** — To store prefix sums in the hashmap.

---

Let me know if you need the same code in Python or want a dry run explanation!
