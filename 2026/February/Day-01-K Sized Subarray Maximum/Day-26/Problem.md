# Isomorphic Strings

## Difficulty: Easy

## Problem Statement

Given two strings **s1** and **s2** consisting of only lowercase English letters and of **equal length**, check if these two strings are **isomorphic** to each other.

Two strings are isomorphic if the characters in `s1` can be replaced to get `s2`.

### Rules:

* Each character must map to exactly one character.
* The mapping must be consistent throughout the string.
* A character may map to itself.
* No two different characters may map to the same character.

---

## Examples

### Example 1

**Input:**
s1 = "aab"
s2 = "xxy"

**Output:**
true

**Explanation:**
Each character in s1 can be consistently mapped to a unique character in s2:

* a → x
* b → y

---

### Example 2

**Input:**
s1 = "aab"
s2 = "xyz"

**Output:**
false

**Explanation:**
Character 'a' in s1 maps to two different characters ('x' and 'y') in s2.

---

### Example 3

**Input:**
s1 = "abc"
s2 = "xxz"

**Output:**
false

**Explanation:**
Two different characters ('a' and 'b') in s1 map to the same character ('x') in s2.

---

## Constraints

* 1 ≤ s1.length() = s2.length() ≤ 10^5

---

## Expected Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1) (since only 26 lowercase letters are used)

---

## Notes

* Use two hash maps (or arrays of size 256/26) to maintain forward and backward mapping.
* Traverse both strings simultaneously and verify consistency at each step.
