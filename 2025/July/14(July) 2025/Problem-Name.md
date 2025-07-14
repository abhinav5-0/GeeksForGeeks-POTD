# Cutting Binary String

**Difficulty:** Medium
**Accuracy:** 49.71%
**Submissions:** 37K+
**Points:** 4

## Problem Statement

You are given a binary string `s` consisting only of characters `'0'` and `'1'`. Your task is to split this string into the **minimum number of non-empty substrings** such that:

1. Each substring represents a **power of 5** in decimal (e.g., 1, 5, 25, 125, ...).
2. No substring should have **leading zeros**.

Return the **minimum number** of such pieces the string can be divided into.

**Note:** If it is not possible to split the string in this way, return `-1`.

## Examples

### Example 1:

**Input:**

```
s = "101101101"
```

**Output:**

```
3
```

**Explanation:**
The string can be split into three substrings: "101", "101", and "101", each of which is 5 in decimal (a power of 5).

---

### Example 2:

**Input:**

```
s = "1111101"
```

**Output:**

```
1
```

**Explanation:**
The string "1111101" represents 125 in decimal, which is a power of 5.

---

### Example 3:

**Input:**

```
s = "00000"
```

**Output:**

```
-1
```

**Explanation:**
There is no valid substring that can be interpreted as a power of 5.

## Constraints

* `1 <= s.size() <= 30`

## Function Signature

```cpp
class Solution {
  public:
    int cuts(string s);
};
```

## Approach

* Use **Dynamic Programming (DP)** where `dp[i]` denotes the minimum cuts for substring `s[0..i]`.
* For every index `i`, try every possible starting point `j` and check if `s[j..i]`:

  * Has no leading zero.
  * Represents a power of 5.
* If valid, update `dp[i] = min(dp[i], dp[j-1] + 1)`.
* If no valid split is found, return `-1`.

## Helper Method

* A helper function checks whether a binary substring converts to a decimal number that is a power of 5.
* This is done using modulo and division checks.
