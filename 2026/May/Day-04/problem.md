# Palindrome Binary

**Difficulty:** Easy
**Accuracy:** 49.1%
**Submissions:** 22K+
**Points:** 2

---

## Problem Statement

Given an integer `n`, determine whether its binary representation forms a palindrome.

Return `true` if the binary representation of `n` is a palindrome; otherwise, return `false`.

> A binary representation is considered a palindrome if it reads the same forward and backward.

---

## Examples

### Example 1

```
Input: n = 17
Output: true
```

**Explanation:** Binary representation of 17 is `(10001)₂`, which is a palindrome.

### Example 2

```
Input: n = 16
Output: false
```

**Explanation:** Binary representation of 16 is `(10000)₂`, which is not a palindrome.

---

## Constraints

* `1 ≤ n ≤ 10^9`

---

## Expected Complexity

* **Time Complexity:** O(log n)
* **Auxiliary Space:** O(1)

---

## Approach

1. Extract bits of the number from both ends.
2. Compare the leftmost and rightmost bits.
3. Move inward and continue comparison.
4. If all bits match → palindrome.

---

## C++ Solution

```cpp
class Solution {
public:
    bool isBinaryPalindrome(int n) {
        int left = 31;
        int right = 0;

        // find highest set bit
        while (left > right && ((n >> left) & 1) == 0) {
            left--;
        }

        while (left > right) {
            int lbit = (n >> left) & 1;
            int rbit = (n >> right) & 1;

            if (lbit != rbit) return false;

            left--;
            right++;
        }

        return true;
    }
};
```

---

## Java Solution

```java
class Solution {
    public boolean isBinaryPalindrome(int n) {
        int left = 31;
        int right = 0;

        while (left > right && ((n >> left) & 1) == 0) {
            left--;
        }

        while (left > right) {
            int lbit = (n >> left) & 1;
            int rbit = (n >> right) & 1;

            if (lbit != rbit) return false;

            left--;
            right++;
        }

        return true;
    }
}
```

---

## Python Solution

```python
class Solution:
    def isBinaryPalindrome(self, n: int) -> bool:
        left = n.bit_length() - 1
        right = 0

        while left > right:
            if ((n >> left) & 1) != ((n >> right) & 1):
                return False
            left -= 1
            right += 1

        return True
```

---

## Alternative Approach (String)

Convert the number to binary string and check palindrome.

```python
return bin(n)[2:] == bin(n)[2:][::-1]
```

---

## Summary

* Compare bits from both ends.
* Efficient solution avoids string conversion.
* Works in `O(log n)` time.
