# Form the Largest Number

**Difficulty:** Medium
**Accuracy:** 37.82%
**Submissions:** 182K+
**Points:** 4

---

## Problem Statement

Given an array of integers `arr[]` representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the largest possible number. Since the result may be very large, return it as a string.

---

## Examples

### Example 1

**Input:**
`arr[] = [3, 30, 34, 5, 9]`

**Output:**
`9534330`

**Explanation:**
Arrangement `[9, 5, 34, 3, 30]` gives the largest value.

---

### Example 2

**Input:**
`arr[] = [54, 546, 548, 60]`

**Output:**
`6054854654`

**Explanation:**
Arrangement `[60, 548, 546, 54]` gives the largest value.

---

### Example 3

**Input:**
`arr[] = [3, 4, 6, 5, 9]`

**Output:**
`96543`

**Explanation:**
Arrangement `[9, 6, 5, 4, 3]` gives the largest value.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i] ≤ 10^5`

---

## Approach

1. Convert each integer to a string.
2. Sort the strings using a **custom comparator**:

   * For two numbers `a` and `b`, compare `a+b` and `b+a`.
   * Place `a` before `b` if `(a+b) > (b+a)`.
3. Concatenate the sorted numbers.
4. Handle the **leading zero case**: if the first element is `"0"`, return `"0"`.

---

## C++ Solution

```cpp
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // Convert numbers to strings
        vector<string> nums;
        for (int num : arr) {
            nums.push_back(to_string(num));
        }

        // Custom comparator for sorting
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // If the largest number is "0", return "0"
        if (nums[0] == "0") return "0";

        // Concatenate result
        string result = "";
        for (string &s : nums) {
            result += s;
        }

        return result;
    }
};
```

---

## Complexity Analysis

* **Sorting:** `O(n log n * k)` where `k` is the average length of numbers (≤ 6 digits).
* **Concatenation:** `O(n * k)`.
* **Overall:** Efficient for `n ≤ 10^5`.

---
