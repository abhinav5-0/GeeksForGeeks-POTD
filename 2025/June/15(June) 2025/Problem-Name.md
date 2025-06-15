## Problem: Smallest Divisor

**Difficulty:** Medium
**Accuracy:** 50.74%
**Submissions:** 21K+
**Points:** 4
**Average Time:** 25m

---

### Problem Statement:

Given an integer array `arr[]` and an integer `k` (where `k ≥ arr.length`), find the smallest positive integer divisor such that the sum of the ceiling values of each element in `arr[]` divided by this divisor is less than or equal to `k`.

---

### Examples:

**Input:**
`arr[] = [1, 2, 5, 9]`, `k = 6`
**Output:**
`5`
**Explanation:**
5 is the smallest divisor having sum of quotients:
`ceil(1/5) + ceil(2/5) + ceil(5/5) + ceil(9/5) = 1 + 1 + 1 + 2 = 5` ≤ 6

**Input:**
`arr[] = [1, 1, 1, 1]`, `k = 4`
**Output:**
`1`
**Explanation:**
1 is the smallest divisor having sum of quotients:
`ceil(1/1) * 4 = 4` ≤ 4

---

### Constraints:

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^6`
* `arr.size() ≤ k ≤ 10^6`

---

### C++ Function Signature:

```cpp
class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
    }
};
```

---

### Optimal Approach (Binary Search):

1. Initialize `left = 1` and `right = max(arr)`.
2. Use binary search to find the smallest divisor such that the sum of `ceil(arr[i] / divisor)` ≤ `k`.
3. Use integer math for ceiling: `(num + divisor - 1) / divisor`

---

### Complete Solution:

```cpp
class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = 0;

            for (int num : arr) {
                sum += (num + mid - 1) / mid;
            }

            if (sum <= k) {
                answer = mid;     // try to minimize the divisor
                right = mid - 1;
            } else {
                left = mid + 1;   // need bigger divisor
            }
        }
        return answer;
    }
};
```

---

### Time Complexity:

* **O(n log m)** where `n = arr.size()` and `m = max(arr)`

### Space Complexity:

* **O(1)** (excluding input array)

---

Let me know if you need the Python version or test cases!
