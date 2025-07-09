# Sum of Subarray Minimums

**Difficulty:** Medium
**Accuracy:** 46.92%
**Submissions:** 20K+
**Points:** 4
**Average Time:** 30m

---

## Problem Statement

Given an array `arr[]` of positive integers, find the total sum of the minimum elements of every possible subarray.

**Note:** It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

---

## Examples

### Example 1:

**Input:**

```
arr[] = [3, 1, 2, 4]
```

**Output:**

```
17
```

**Explanation:**
Subarrays are:

* \[3], \[1], \[2], \[4]
* \[3, 1], \[1, 2], \[2, 4]
* \[3, 1, 2], \[1, 2, 4]
* \[3, 1, 2, 4]

Minimums of these subarrays:

* 3, 1, 2, 4
* 1, 1, 2
* 1, 1
* 1

Total sum = 3 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1 + 1 = **17**

### Example 2:

**Input:**

```
arr[] = [71, 55, 82, 55]
```

**Output:**

```
593
```

**Explanation:**
The sum of the minimums of all possible subarrays is 593.

---

## Constraints

* 1 <= arr.size() <= 3 \* 10^4
* 1 <= arr\[i] <= 10^3

---

## Function Signature

```cpp
class Solution {
  public:
    int sumSubMins(vector<int> &arr);
};
```

---

## Optimal Approach

Use **Monotonic Stack** to find:

* Previous Less Element (PLE)
* Next Less Element (NLE)

For each `arr[i]`, contribution to result:

```
arr[i] * (i - ple[i]) * (nle[i] - i)
```

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`
