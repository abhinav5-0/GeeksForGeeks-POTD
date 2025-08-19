# Farthest Smaller Right

**Difficulty:** Medium
**Accuracy:** 52.41%
**Submissions:** 4K+
**Points:** 4

---

## Problem Statement

You are given an array `arr[]`. For each element at index `i` (0-based indexing), find the farthest index `j` to the right (i.e., `j > i`) such that `arr[j] < arr[i]`. If no such index exists for a given position, return `-1` for that index. Return the resulting array of answers.

---

## Examples

### Example 1

**Input:**

```cpp
arr[] = [2, 5, 1, 3, 2]
```

**Output:**

```cpp
[2, 4, -1, 4, -1]
```

**Explanation:**

* arr\[0] = 2 → farthest smaller right is arr\[2] = 1.
* arr\[1] = 5 → farthest smaller right is arr\[4] = 2.
* arr\[2] = 1 → no smaller right → -1.
* arr\[3] = 3 → farthest smaller right is arr\[4] = 2.
* arr\[4] = 2 → no elements to the right → -1.

---

### Example 2

**Input:**

```cpp
arr[] = [2, 3, 5, 4, 1]
```

**Output:**

```cpp
[4, 4, 4, 4, -1]
```

**Explanation:**

* arr\[4] is the farthest smaller element for arr\[0], arr\[1], arr\[2], and arr\[3].

---

## Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `1 ≤ arr[i] ≤ 10^6`

---

## Optimized Solution (Suffix Min + Binary Search)

We use a suffix minimum array and binary search:

1. Compute `suff[i]` = minimum value from index `i` to the end.
2. For each `arr[i]`, perform binary search in `suff[i+1 ... n-1]` to find the farthest index `j` such that `suff[j] < arr[i]`.

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        vector<int> suff(n);
        
        // Step 1: Build suffix minimum array
        suff[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i)
            suff[i] = min(arr[i], suff[i+1]);
        
        // Step 2: For each element, binary search in suffix
        for(int i = 0; i < n; ++i) {
            int lo = i+1, hi = n-1, res = -1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(suff[mid] < arr[i]) {
                    res = mid;
                    lo = mid+1; // try farther right
                } else {
                    hi = mid-1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(n log n) (binary search per element)
* **Space Complexity:** O(n) (suffix array + result array)

---
