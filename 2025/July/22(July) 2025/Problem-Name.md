## Problem: Smallest Positive Missing Number

**Difficulty:** Medium  
**Accuracy:** 25.13%  
**Submissions:** 438K+  
**Points:** 4

### Problem Statement:
You are given an integer array `arr[]`. Your task is to find the smallest positive number missing from the array.

**Note:** Positive numbers start from 1. The array can have negative integers too.

### Examples:
**Input:** `arr[] = [2, -3, 4, 1, 1, 7]`  
**Output:** `3`  
**Explanation:** Smallest positive missing number is 3.

**Input:** `arr[] = [5, 3, 2, 5, 1]`  
**Output:** `4`  
**Explanation:** Smallest positive missing number is 4.

**Input:** `arr[] = [-8, 0, -1, -4, -3]`  
**Output:** `1`  
**Explanation:** Smallest positive missing number is 1.

### Constraints:
- `1 ≤ arr.size() ≤ 10^5`
- `-10^6 ≤ arr[i] ≤ 10^6`

---

### Approach:
We use an in-place hashing technique (similar to cyclic sort) to rearrange the elements in such a way that each element `x` is placed at index `x - 1`, if `1 <= x <= n`.

After the rearrangement, we simply check the first index `i` where `arr[i] != i + 1`. That `i + 1` is the smallest missing positive number.

### Time and Space Complexity:
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` (in-place)

---

### Solution (C++):
```cpp
class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Place each number at its correct index if possible
        for (int i = 0; i < n; ++i) {
            while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Find the first location where index doesn't match the value
        for (int i = 0; i < n; ++i) {
            if (arr[i] != i + 1)
                return i + 1;
        }

        // If all positions are correct, then smallest missing is n+1
        return n + 1;
    }
};
```

---

Let me know if you want the Python version or brute-force/hash-set alternatives.
