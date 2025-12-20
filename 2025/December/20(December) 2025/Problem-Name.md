# Search Insert Position of K in a Sorted Array

## Problem Statement

Given a **sorted array** `arr[]` (0-index based) of **distinct integers** and an integer `k`, find:

* The index of `k` if it is present in the array.
* Otherwise, the index where `k` should be inserted to maintain the sorted order.

---

## Examples

### Example 1

**Input:**

```
arr = [1, 3, 5, 6], k = 5
```

**Output:**

```
2
```

**Explanation:** `5` is present at index `2`.

---

### Example 2

**Input:**

```
arr = [1, 3, 5, 6], k = 2
```

**Output:**

```
1
```

**Explanation:** `2` is not present, but inserting it at index `1` keeps the array sorted.

---

### Example 3

**Input:**

```
arr = [2, 6, 7, 10, 14], k = 15
```

**Output:**

```
5
```

**Explanation:** `15` should be inserted after the last element.

---

## Approach (Binary Search)

Since the array is sorted, we use **binary search**:

* If `k` is found, return its index.
* If not found, the position where the search ends (`low`) is the correct insert position.

---

## C++ Implementation

```cpp
class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == k)
                return mid;
            else if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        // low is the correct insert position
        return low;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(log n)`
* **Space Complexity:** `O(1)`

---

## Key Takeaway

Binary search not only helps in finding an element efficiently but also directly gives the correct **insert position** when the element is absent.
