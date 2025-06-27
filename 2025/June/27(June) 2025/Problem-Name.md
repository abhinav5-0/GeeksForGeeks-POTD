# Mobile Numeric Keypad

**Difficulty:** Medium
**Accuracy:** 32.6%
**Submissions:** 66K+
**Points:** 4
**Average Time:** 30m

---

## Problem Statement

There is a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly **above, below, to the left, or to the right** of it.

For example, if you press `5`, then pressing `2`, `4`, `6`, or `8` is allowed. However, **diagonal movements** and pressing the bottom row corner buttons (`*` and `#`) are not allowed.

Given an integer `n`, determine how many unique sequences of length `n` can be formed by pressing buttons on the keypad, starting from any digit.

---

## Keypad Layout

```
1 2 3
4 5 6
7 8 9
* 0 #
```

---

## Input

* An integer `n` denoting the length of sequences.

## Output

* An integer representing the number of unique sequences of length `n`.

---

## Constraints

* `1 <= n <= 15`

---

## Examples

### Example 1:

**Input:**

```
n = 1
```

**Output:**

```
10
```

**Explanation:**
Each digit from 0 to 9 can be used as a 1-digit sequence, resulting in 10 sequences.

---

### Example 2:

**Input:**

```
n = 2
```

**Output:**

```
36
```

**Explanation:**
From each digit, count valid movements to form 2-digit sequences:

* From 0 → 00, 08
* From 1 → 11, 12, 14
* From 2 → 22, 21, 23, 25
* From 3 → 33, 32, 36
  ...and so on.

---

## Notes

* Use dynamic programming to store intermediate results.
* Define allowed transitions for each digit and build solutions iteratively.

---

## Tags

`Dynamic Programming` `Combinatorics` `Matrix Traversal`

---

## Function Signature (C++)

```cpp
class Solution {
  public:
    int getCount(int n);
};
```

Implement `getCount(int n)` to return the total number of valid sequences of length `n`.
