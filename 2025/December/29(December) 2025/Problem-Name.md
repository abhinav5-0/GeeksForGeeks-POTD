# K-th Element of Two Sorted Arrays

## Problem Statement

Given two **sorted arrays** `a[]` and `b[]` and an integer `k`, find the element that would appear at the **k-th position** in the combined sorted array formed by merging both arrays.

---

## Examples

### Example 1

**Input**:

```
a = [2, 3, 6, 7, 9]
b = [1, 4, 8, 10]
k = 5
```

**Output**:

```
6
```

**Explanation**:
Combined sorted array:

```
[1, 2, 3, 4, 6, 7, 8, 9, 10]
```

The 5th element is `6`.

---

### Example 2

**Input**:

```
a = [1, 4, 8, 10, 12]
b = [5, 7, 11, 15, 17]
k = 6
```

**Output**:

```
10
```

---

## Constraints

* `1 ≤ a.size(), b.size() ≤ 10^6`
* `1 ≤ k ≤ a.size() + b.size()`
* `0 ≤ a[i], b[i] ≤ 10^8`

---

## Optimal Approach (Binary Search on Partition)

Instead of merging the arrays, we use **binary search** to find a valid partition such that:

* The left part contains exactly `k` elements
* All elements on the left are **less than or equal to** all elements on the right

We always apply binary search on the **smaller array** for efficiency.

---

## Algorithm Steps

1. Let `cutA` be the number of elements taken from array `a`
2. Let `cutB = k - cutA`
3. Check if the partition is valid:

   ```
   max(leftA, leftB) ≤ min(rightA, rightB)
   ```
4. If valid, the answer is `max(leftA, leftB)`
5. Otherwise, adjust binary search range

---

## C++ Implementation

```cpp
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();
        
        // Ensure binary search on smaller array
        if (n > m) return kthElement(b, a, k);
        
        int low = max(0, k - m);
        int high = min(k, n);
        
        while (low <= high) {
            int cutA = (low + high) / 2;
            int cutB = k - cutA;
            
            int leftA  = (cutA == 0) ? INT_MIN : a[cutA - 1];
            int leftB  = (cutB == 0) ? INT_MIN : b[cutB - 1];
            int rightA = (cutA == n) ? INT_MAX : a[cutA];
            int rightB = (cutB == m) ? INT_MAX : b[cutB];
            
            if (leftA <= rightB && leftB <= rightA) {
                return max(leftA, leftB);
            }
            else if (leftA > rightB) {
                high = cutA - 1;
            }
            else {
                low = cutA + 1;
            }
        }
        return -1; // Should never reach here
    }
};
```

---

## Complexity Analysis

* **Time Complexity**: `O(log(min(n, m)))`
* **Space Complexity**: `O(1)`

---

## Key Takeaways

* Avoid merging arrays for large constraints
* Binary search on partitions is highly efficient
* Same technique is used in **Median of Two Sorted Arrays**

---

✅ **Interview-friendly | Efficient | Scalable Solution**
