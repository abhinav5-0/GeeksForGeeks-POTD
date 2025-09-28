# Longest Bounded-Difference Subarray

**Difficulty:** Medium  
**Accuracy:** 58.27%  
**Submissions:** 25K+  
**Points:** 4

---

## Problem Statement
Given an array of positive integers `arr[]` and a non-negative integer `x`, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than `x`.

If multiple such subarrays exist, return the one that starts at the smallest index.

---

## Examples

**Input:**  
`arr[] = [8, 4, 5, 6, 7], x = 3`  
**Output:**  
`[4, 5, 6, 7]`  
**Explanation:** The subarray `[4, 5, 6, 7]` contains no two elements whose absolute difference is greater than 3.

---

**Input:**  
`arr[] = [1, 10, 12, 13, 14], x = 2`  
**Output:**  
`[12, 13, 14]`  
**Explanation:** The subarray `[12, 13, 14]` contains no two elements whose absolute difference is greater than 2.

---

## Constraints
- 1 ≤ arr.size() ≤ 10^5
- 1 ≤ arr[i] ≤ 10^9
- 0 ≤ x ≤ 10^9

---

## Approach
We need the longest subarray such that the difference between the maximum and minimum elements is ≤ `x`. This is a **sliding window problem** where we maintain both the minimum and maximum efficiently using two deques:

1. Use **two deques**:
   - `maxDq`: maintains elements in decreasing order (front = maximum).
   - `minDq`: maintains elements in increasing order (front = minimum).

2. Iterate with a right pointer:
   - Add `arr[right]` into both deques while maintaining their order.

3. If condition `(maxDq.front() - minDq.front() > x)` breaks:
   - Shrink the window from the left.
   - Remove elements that are out of the window from the deques.

4. Keep track of the **longest window length** and its **starting index**.

5. Extract and return the corresponding subarray.

---

## C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        deque<int> maxDq, minDq; 
        int left = 0, bestLen = 0, bestStart = 0;

        for (int right = 0; right < n; right++) {
            // Maintain max deque (decreasing)
            while (!maxDq.empty() && arr[maxDq.back()] < arr[right])
                maxDq.pop_back();
            maxDq.push_back(right);

            // Maintain min deque (increasing)
            while (!minDq.empty() && arr[minDq.back()] > arr[right])
                minDq.pop_back();
            minDq.push_back(right);

            // If condition breaks, shrink window
            while (!maxDq.empty() && !minDq.empty() &&
                   arr[maxDq.front()] - arr[minDq.front()] > x) {
                if (maxDq.front() == left) maxDq.pop_front();
                if (minDq.front() == left) minDq.pop_front();
                left++;
            }

            // Update best answer
            if (right - left + 1 > bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
        }

        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    }
};
```

---

## Dry Run Example
Input:  
`arr = [8, 4, 5, 6, 7], x = 3`

- Start with `[8]` → valid.  
- Expand → `[8,4]` → invalid (`8-4=4>x`), move left.  
- Window adjusts to `[4,5,6,7]`, valid (`7-4=3`).  
- Best length = 4, starting at index 1.  

Output: `[4, 5, 6, 7]`

---

## Complexity Analysis
- **Time Complexity:** O(n), since each element enters and exits the deques at most once.  
- **Space Complexity:** O(n), for storing indices in the deques.
