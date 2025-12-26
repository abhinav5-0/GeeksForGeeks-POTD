# Kth Missing Positive Number in a Sorted Array

## Problem Statement

Given a sorted array of **distinct positive integers** `arr[]`, you need to find the **kth positive number that is missing** from the array.

---

## Examples

### Example 1

**Input:**

```
arr = [2, 3, 4, 7, 11], k = 5
```

**Output:**

```
9
```

**Explanation:** Missing numbers are `1, 5, 6, 8, 9, 10…` → 5th missing is `9`

---

### Example 2

**Input:**

```
arr = [1, 2, 3], k = 2
```

**Output:**

```
5
```

**Explanation:** Missing numbers are `4, 5, 6…` → 2nd missing is `5`

---

### Example 3

**Input:**

```
arr = [3, 5, 9, 10, 11, 12], k = 2
```

**Output:**

```
2
```

**Explanation:** Missing numbers are `1, 2, 4, 6…` → 2nd missing is `2`

---

## Key Insight

For a given index `i` (0-based):

```
missing numbers till arr[i] = arr[i] - (i + 1)
```

This works because ideally, the value at index `i` should be `i + 1` if no numbers were missing.

---

## Optimized Approach (Binary Search)

1. Perform binary search on the array indices
2. Find the first index where the count of missing numbers is **greater than or equal to `k`**
3. The answer will be:

```
k + index
```

---

## C++ Implementation

```cpp
class Solution {
public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return k + low;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`

---

## Notes

* Works efficiently even for large arrays (`n ≤ 10^5`)
* Handles cases where missing numbers occur before the first element

---

✅ **Recommended approach for interviews and competitive programming**
