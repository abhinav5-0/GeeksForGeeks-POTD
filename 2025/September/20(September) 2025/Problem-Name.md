# Longest Subarray Length

## Problem Statement
You are given an array of integers `arr[]`. Your task is to find the length of the longest subarray such that all the elements of the subarray are smaller than or equal to the length of the subarray.

### Examples

**Input:** `arr[] = [1, 2, 3]`  
**Output:** `3`  
**Explanation:** The longest subarray is the entire array itself, which has a length of 3. All elements in the subarray are less than or equal to 3.

**Input:** `arr[] = [6, 4, 2, 5]`  
**Output:** `0`  
**Explanation:** There is no subarray where all elements are less than or equal to the length of the subarray. The longest subarray is empty, which has a length of 0.

### Constraints
- 1 ≤ arr.size() ≤ 10^5
- 1 ≤ arr[i] ≤ 10^9

---

## Approach
1. **Binary Search on Answer:**
   - The possible subarray length `L` ranges from `1` to `n`.
   - Use binary search to find the maximum valid `L`.

2. **Check Validity of a Candidate L:**
   - For each subarray of size `L`, check if `max(subarray) <= L`.
   - Use a sliding window maximum (deque) to efficiently compute the maximum in O(n).

3. **Result:**
   - Return the largest valid `L`, or `0` if no subarray exists.

---

## Complexity Analysis
- Each validity check takes **O(n)** using sliding window.
- Binary search performs **O(log n)** checks.
- Overall complexity: **O(n log n)**.

---

## C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int low = 1, high = n, ans = 0;

        auto can = [&](int L) {
            deque<int> dq;
            for (int i = 0; i < n; i++) {
                while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
                dq.push_back(i);

                if (dq.front() <= i - L) dq.pop_front();

                if (i >= L - 1) {
                    if (arr[dq.front()] <= L) return true;
                }
            }
            return false;
        };

        while (low <= high) {
            int mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
