# Maximize Number of 1's

**Difficulty:** Medium
**Accuracy:** 39.46%
**Submissions:** 67K+
**Points:** 4
**Average Time:** 20m

---

## Problem Statement

Given a binary array `arr[]` containing only `0s` and `1s` and an integer `k`, you are allowed to flip at most `k` `0s` to `1s`. Find the maximum number of consecutive `1's` that can be obtained in the array after performing the operation at most `k` times.

---

## Examples

### Example 1

**Input:**

```
arr[] = [1, 0, 1], k = 1
```

**Output:**

```
3
```

**Explanation:**
By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.

---

### Example 2

**Input:**

```
arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
```

**Output:**

```
5
```

**Explanation:**
By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.

---

### Example 3

**Input:**

```
arr[] = [1, 1], k = 2
```

**Output:**

```
2
```

**Explanation:**
Since the array is already having the max consecutive 1's, hence we don’t need to perform any operation. Hence the answer is 2.

---

## Constraints

* 1 ≤ arr.size() ≤ 10^5
* 0 ≤ k ≤ arr.size()
* 0 ≤ arr\[i] ≤ 1

---

## Approach

This problem can be solved using the **sliding window (two pointers)** technique:

1. Use two pointers (`left`, `right`) to represent a window.
2. Expand the window by moving `right`.
3. Count the zeros inside the window.
4. If the count of zeros exceeds `k`, move `left` forward until zeros ≤ k.
5. Keep track of the maximum window size where zeros ≤ k.

This ensures we always maintain the longest valid subarray.

---

## Complexity Analysis

* **Time Complexity:** O(n), since each element is processed at most twice.
* **Space Complexity:** O(1), constant extra space.

---

## C++ Solution

```cpp
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;
        
        while (right < arr.size()) {
            // Expand window
            if (arr[right] == 0) {
                zeroCount++;
            }
            
            // Shrink window if zeros exceed k
            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            
            // Update maximum window size
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};
```
