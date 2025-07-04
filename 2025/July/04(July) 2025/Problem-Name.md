# Subarrays With At Most K Distinct Integers

**Difficulty:** Medium
**Accuracy:** 62.15%
**Submissions:** 12K+
**Points:** 4

## Problem Statement

You are given an array `arr[]` of positive integers and an integer `k`. Your task is to find the number of subarrays in `arr[]` where the count of distinct integers is **at most** `k`.

**Note:** A subarray is a contiguous part of an array.

---

## Examples

### Example 1

**Input:**

```
arr[] = [1, 2, 2, 3], k = 2
```

**Output:**

```
9
```

**Explanation:**
Subarrays with at most 2 distinct elements are:
\[1], \[2], \[2], \[3], \[1, 2], \[2, 2], \[2, 3], \[1, 2, 2], \[2, 2, 3]

---

### Example 2

**Input:**

```
arr[] = [1, 1, 1], k = 1
```

**Output:**

```
6
```

**Explanation:**
Subarrays with at most 1 distinct element are:
\[1], \[1], \[1], \[1, 1], \[1, 1], \[1, 1, 1]

---

### Example 3

**Input:**

```
arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
```

**Output:**

```
24
```

**Explanation:**
There are 24 subarrays with at most 2 distinct elements.

---

## Constraints

* 1 ≤ `arr.size()` ≤ 2 \* 10^4
* 1 ≤ `k` ≤ 2 \* 10^4
* 1 ≤ `arr[i]` ≤ 10^9

---

## Approach

Use the **Sliding Window** technique with a hashmap to count the frequency of elements in the current window. Whenever the number of distinct elements exceeds `k`, shrink the window from the left until the constraint is met. For each position of the `right` pointer, add `(right - left + 1)` to the result.

---

## C++ Function Skeleton

```cpp
class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;

        for (int right = 0; right < arr.size(); right++) {
            if (freq[arr[right]] == 0) k--;  // new distinct element
            freq[arr[right]]++;

            while (k < 0) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) k++;
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
```
