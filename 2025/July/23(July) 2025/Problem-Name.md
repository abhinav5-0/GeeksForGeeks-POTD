## Problem: Sum of Subarrays

**Difficulty:** Medium  
**Accuracy:** 23.85%  
**Submissions:** 38K+  
**Points:** 4

### Problem Statement:
Given an array `arr[]`, find the **sum of all the subarrays** of the given array.

> **Note:** It is guaranteed that the total sum will fit within a 32-bit integer range.

### Examples:

**Input:**
``` 
arr[] = [1, 2, 3] 
```
**Output:**
```
20
```
**Explanation:**  
All subarray sums are:  
[1] = 1, [2] = 2, [3] = 3, [1, 2] = 3, [2, 3] = 5, [1, 2, 3] = 6  
Total sum = 1 + 2 + 3 + 3 + 5 + 6 = **20**

**Input:**
```
arr[] = [1, 3]
```
**Output:**
```
8
```
**Explanation:**  
All subarray sums are:  
[1] = 1, [3] = 3, [1, 3] = 4  
Total = 1 + 3 + 4 = **8**

### Constraints:
- 1 ≤ arr.size() ≤ 10^5  
- 0 ≤ arr[i] ≤ 10^4

---

### Approach:
We use a mathematical observation:
Each element `arr[i]` appears in exactly **(i + 1) * (n - i)** subarrays.

- `i + 1` ways to choose a starting point that includes `arr[i]`
- `n - i` ways to choose an ending point that includes `arr[i]`

So the total contribution of `arr[i]` to the final sum is:
```
arr[i] * (i + 1) * (n - i)
```

### Final Formula:
```
Total Sum = Σ arr[i] * (i + 1) * (n - i)
```

### C++ Code:
```cpp
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; ++i) {
            totalSum += arr[i] * (i + 1) * (n - i);
        }
        
        return totalSum;
    }
};
```

### Time Complexity:
- O(n), where n is the size of the array

### Space Complexity:
- O(1), constant extra space
