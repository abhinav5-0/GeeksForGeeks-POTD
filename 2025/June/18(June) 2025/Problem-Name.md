# Problem: All Palindromic Partitions

**Difficulty:** Medium
**Accuracy:** 61.47%
**Submissions:** 27K+
**Points:** 4
**Average Time:** 30m

## Problem Statement

Given a string `s`, find all possible ways to partition it such that every substring in the partition is a palindrome.

## Input

* A single string `s` where `1 <= s.size() <= 20`.

## Output

* Return a list of lists where each list contains a valid palindromic partition of the input string.

## Examples

### Example 1

**Input:**

```
s = "geeks"
```

**Output:**

```
[["g", "e", "e", "k", "s"], ["g", "ee", "k", "s"]]
```

**Explanation:**
Only \["g", "e", "e", "k", "s"] and \["g", "ee", "k", "s"] are valid palindromic partitions.

### Example 2

**Input:**

```
s = "abcba"
```

**Output:**

```
[["a", "b", "c", "b", "a"], ["a", "bcb", "a"], ["abcba"]]
```

**Explanation:**
All substrings in each partition are palindromes.

## Constraints

* `1 <= s.size() <= 20`
* All characters in `s` are lowercase English letters.

## Notes

* A palindrome is a string that reads the same forward and backward.
* The order of partitions in the output does not matter.

## Tags

Backtracking, String, Recursion
