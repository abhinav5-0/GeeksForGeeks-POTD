## Minimum Sum

**Difficulty:** Medium  
**Accuracy:** 17.14%  
**Submissions:** 149K+  
**Points:** 4

### Problem Statement
Given an array `arr[]` consisting of digits (0-9), your task is to form **two numbers** using **all the digits** such that their **sum is minimized**. Return the **minimum possible sum** as a **string** with **no leading zeroes**.

---

### Examples:

#### Example 1:
**Input:** `arr[] = [6, 8, 4, 5, 2, 3]`  
**Output:** `"604"`  
**Explanation:** The minimum sum is formed by numbers `358` and `246`.

#### Example 2:
**Input:** `arr[] = [5, 3, 0, 7, 4]`  
**Output:** `"82"`  
**Explanation:** The minimum sum is formed by numbers `35` and `047` (leading zero is ignored).

#### Example 3:
**Input:** `arr[] = [9, 4]`  
**Output:** `"13"`  
**Explanation:** The minimum sum is formed by numbers `9` and `4`.

---

### Constraints:
- `2 <= arr.size() <= 10^6`
- `0 <= arr[i] <= 9`

---

### Function Signature
```cpp
class Solution {
  public:
    string minSum(vector<int> &arr);
};
```

### Approach:
1. Sort the input array.
2. Distribute digits alternatively between two strings `num1` and `num2`.
3. Perform string-based addition of `num1` and `num2` to handle large numbers.
4. Return the result after trimming leading zeroes.

---
