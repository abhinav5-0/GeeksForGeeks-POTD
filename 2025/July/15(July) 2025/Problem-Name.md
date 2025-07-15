# Divisible by 13

**Difficulty:** Medium
**Accuracy:** 56.69%
**Submissions:** 8K+
**Points:** 4

---

## Problem Statement

Given a number represented as a string `s` (which may be very large), check whether it is divisible by 13 or not.

---

## Input

* A single string `s`, representing a non-negative integer.

**Constraints:**

* `1 ≤ s.length ≤ 10^5`
* The string contains only digits ('0'–'9').

---

## Output

* Return `true` if the number is divisible by 13.
* Return `false` otherwise.

---

## Examples

### Example 1:

**Input:**

```
s = "2911285"
```

**Output:**

```
true
```

**Explanation:**
2911285 divided by 13 equals 223945, which is a whole number.

### Example 2:

**Input:**

```
s = "27"
```

**Output:**

```
false
```

**Explanation:**
27 divided by 13 is not a whole number.

---

## Approach

* Initialize `remainder` as 0.
* Traverse the string digit by digit.
* For each digit, update the remainder as:

  ```
  remainder = (remainder * 10 + digit) % 13
  ```
* At the end, if `remainder == 0`, then the number is divisible by 13.

---

## C++ Implementation

```cpp
class Solution {
  public:
    bool divby13(string &s) {
        int remainder = 0;
        for (char c : s) {
            int digit = c - '0';
            remainder = (remainder * 10 + digit) % 13;
        }
        return remainder == 0;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(n), where n is the length of the string.
* **Space Complexity:** O(1), constant extra space used.
