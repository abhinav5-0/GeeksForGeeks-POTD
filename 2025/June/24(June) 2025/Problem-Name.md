# Lexicographically Largest String After K Deletions

**Difficulty:** Medium
**Accuracy:** 65.49%
**Submissions:** 6K+
**Points:** 4
**Average Time:** 15 minutes

---

## Problem Statement

Given a string `s` consisting of lowercase English letters and an integer `k`, your task is to remove exactly `k` characters from the string. The resulting string must be the **largest possible in lexicographical order**, while maintaining the **relative order** of the remaining characters.

---

## Input

* A string `s` of lowercase English letters.
* An integer `k` representing the number of characters to remove.

---

## Output

* Return the lexicographically largest string possible after removing exactly `k` characters from `s`.

---

## Constraints

* `1 ≤ s.length ≤ 10^5`
* `0 ≤ k < s.length`

---

## Examples

### Example 1:

**Input:**

```
s = "ritz"
k = 2
```

**Output:**

```
tz
```

**Explanation:**
By removing two characters in all possible ways, we get: "ri", "rt", "rz", "it", "iz", and "tz". Among these, "tz" is lexicographically the largest.

---

### Example 2:

**Input:**

```
s = "zebra"
k = 3
```

**Output:**

```
zr
```

**Explanation:**
Removing "e", "b", and "a" results in "zr", which is the lexicographically largest string.

---

## Approach

To solve this problem efficiently:

* Use a **monotonic decreasing stack** to construct the result.
* Traverse the string from left to right.
* If the current character is greater than the top of the stack and you still have deletions left, pop from the stack.
* Push the current character to the stack.
* After the traversal, resize the stack to hold exactly `n - k` characters (where `n` is the original length of the string).

This approach runs in **O(n)** time and handles input sizes up to `10^5` efficiently.

---

## Tags

`Greedy` `Stack` `Lexicographical Order` `String Manipulation`
