# Sum of All Substrings of a Number

**Difficulty:** Medium
**Accuracy:** 38.11%
**Submissions:** 60K+
**Points:** 4

---

## Problem Statement

Given an integer `s` represented as a string, the task is to compute the sum of all possible substrings of this string.

**Note:**

* The number may have leading zeros.
* It is guaranteed that the total sum will fit within a 32-bit signed integer.

---

## Examples

### Example 1:

**Input:** `s = "6759"`

**Output:** `8421`

**Explanation:**
All possible substrings and their sums:

```
6 + 7 + 5 + 9 + 67 + 75 + 59 + 675 + 759 + 6759 = 8421
```

### Example 2:

**Input:** `s = "421"`

**Output:** `491`

**Explanation:**
All possible substrings and their sums:

```
4 + 2 + 1 + 42 + 21 + 421 = 491
```

---

## Constraints

* 1 <= |s| <= 9

---

## C++ Function Signature

```cpp
class Solution {
  public:
    int sumSubstrings(string &s);
};
```

---

## Efficient Approach (Dynamic Programming)

We iterate through the string and maintain:

* `totalSum`: the overall sum of all substrings.
* `prevSum`: the sum of all substrings ending at the previous character.

For each digit at index `i`, the sum of substrings ending at this digit is:

```
prevSum = prevSum * 10 + (i + 1) * digit
```

This is because each digit contributes to all substrings ending at its position.

### C++ Implementation

```cpp
class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.length();
        long long totalSum = 0;
        long long prevSum = 0;
        int mod = 1000000007; // Optional for large inputs

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            prevSum = (prevSum * 10 + (digit * 1LL * (i + 1))) % mod;
            totalSum = (totalSum + prevSum) % mod;
        }

        return (int)totalSum;
    }
};
```

---

## Notes

* This approach runs in linear time `O(n)`.
* It avoids generating all substrings explicitly.
* The use of modulo `1000000007` ensures results stay within integer limits for large values (optional here due to constraint).

---

## Tags

`Dynamic Programming` `Mathematics` `String`
