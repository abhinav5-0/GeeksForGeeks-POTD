# Longest Substring with Exactly K Unique Characters

**Difficulty:** Medium
**Accuracy:** 34.65%
**Submissions:** 204K+
**Points:** 4

---

## Problem Statement

You are given a string `s` consisting only of lowercase alphabets and an integer `k`. Your task is to find the length of the longest substring that contains **exactly** `k` distinct characters.

If no such substring exists, return `-1`.

---

## Input

* A string `s` of length between `1` and `10^5`, consisting only of lowercase English letters.
* An integer `k` such that `1 <= k <= 26`.

---

## Output

* An integer representing the length of the longest substring of `s` that contains exactly `k` distinct characters. Return `-1` if no such substring exists.

---

## Examples

### Example 1:

**Input:**

```
s = "aabacbebebe"
k = 3
```

**Output:**

```
7
```

**Explanation:**
The longest substring with exactly 3 distinct characters is **"cbebebe"**, which includes `'c'`, `'b'`, and `'e'`.

---

### Example 2:

**Input:**

```
s = "aaaa"
k = 2
```

**Output:**

```
-1
```

**Explanation:**
There's no substring with exactly 2 distinct characters.

---

### Example 3:

**Input:**

```
s = "aabaaab"
k = 2
```

**Output:**

```
7
```

**Explanation:**
The entire string "aabaaab" has exactly 2 unique characters `'a'` and `'b'`, making it the longest valid substring.

---

## Constraints

* `1 <= s.size() <= 10^5`
* `1 <= k <= 26`

---

## Notes

* Use an efficient approach like **sliding window with a hashmap** to track character frequencies.
* Time Complexity should be **O(n)**.

---

## Tags

`Strings`, `Sliding Window`, `HashMap`, `Two Pointers`
