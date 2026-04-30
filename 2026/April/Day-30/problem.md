# Check if an Array is Max Heap

**Difficulty:** Easy
**Accuracy:** 30.97%
**Submissions:** 98K+
**Points:** 2

---

## Problem Statement

Given an array `arr[]`, determine whether it represents the **level-order traversal** of a valid **max heap**.

Return **true** if it does, otherwise return **false**.

---

## Explanation

A **max heap** is a complete binary tree where:

* Every parent node is **greater than or equal to** its children.

For an array representation:

* Left child of index `i` → `2*i + 1`
* Right child of index `i` → `2*i + 2`

---

## Examples

### Example 1

```
Input: arr[] = [90, 15, 10, 7, 12, 2]
Output: true
```

**Explanation:**
Each parent node is greater than or equal to its children, so it satisfies the max-heap property.

---

### Example 2

```
Input: arr[] = [9, 15, 10, 7, 12, 11]
Output: false
```

**Explanation:**

* `9 < 15` → violates max heap property
* `10 < 11` → violates max heap property

---

## Constraints

* `1 ≤ n ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^5`

---

## Approach

Traverse all non-leaf nodes and check:

* If left child exists, ensure `arr[i] >= arr[left]`
* If right child exists, ensure `arr[i] >= arr[right]`

If any condition fails → return `false`

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Code Implementations

### C++

```cpp
class Solution {
public:
    bool isMaxHeap(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
        }
        
        return true;
    }
};
```

---

### Java

```java
class Solution {
    public boolean isMaxHeap(int[] arr) {
        int n = arr.length;
        
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
        }
        
        return true;
    }
}
```

---

### Python

```python
class Solution:
    def isMaxHeap(self, arr):
        n = len(arr)
        
        for i in range((n - 2) // 2 + 1):
            left = 2 * i + 1
            right = 2 * i + 2
            
            if left < n and arr[i] < arr[left]:
                return False
            if right < n and arr[i] < arr[right]:
                return False
        
        return True
```

---

## Key Insight

Only **non-leaf nodes** need to be checked because leaf nodes have no children.

Index of last non-leaf node:

```
(n - 2) // 2
```

---

## Summary

* Use array indexing to simulate heap structure
* Validate parent-child relationship
* Stop early if violation found

---

Happy Coding 🚀
