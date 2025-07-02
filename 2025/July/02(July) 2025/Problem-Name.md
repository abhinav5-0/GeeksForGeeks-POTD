# Longest Subarray with At Most Two Distinct Integers

**Difficulty:** Medium  
**Accuracy:** 47.98%  
**Submissions:** 121K+  
**Points:** 4  
**Average Time:** 30m

## Problem Statement
Given an array `arr[]` consisting of positive integers, your task is to find the length of the longest subarray that contains at most **two distinct integers**.

---

## Examples

### Example 1:
**Input:**
```cpp
arr[] = [2, 1, 2]
```
**Output:**
```
3
```
**Explanation:**
The entire array `[2, 1, 2]` contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.

### Example 2:
**Input:**
```cpp
arr[] = [3, 1, 2, 2, 2, 2]
```
**Output:**
```
5
```
**Explanation:**
The longest subarray containing at most two distinct integers is `[1, 2, 2, 2, 2]`, which has a length of 5.

---

## Constraints
- $1 \leq arr.size() \leq 10^5$
- $1 \leq arr[i] \leq 10^5$

---

## Function Signature
```cpp
class Solution {
  public:
    int totalElements(vector<int> &arr);
};
```

---

## Approach
Use the **sliding window technique** with a **hash map** to track the count of elements in the current window. Expand the window with a right pointer, and if the window has more than 2 distinct elements, move the left pointer to shrink the window.

### Time Complexity:
- `O(n)` — Each element is processed at most twice.

### Space Complexity:
- `O(1)` — Hash map contains at most 2 distinct keys.

---

## Sample Code
```cpp
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> count;
        int start = 0, maxLen = 0;

        for (int end = 0; end < arr.size(); ++end) {
            count[arr[end]]++;

            while (count.size() > 2) {
                count[arr[start]]--;
                if (count[arr[start]] == 0) {
                    count.erase(arr[start]);
                }
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
```

---

## Tags
- Sliding Window
- Hash Map
- Arrays
