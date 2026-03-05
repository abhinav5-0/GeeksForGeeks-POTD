# Longest Substring with K Uniques

**Difficulty:** Medium
**Accuracy:** 34.65%
**Submissions:** 277K+
**Points:** 4

## Problem Statement

You are given a string `s` consisting only of lowercase alphabets and an integer `k`. Your task is to find the **length of the longest substring** that contains **exactly `k` distinct characters**.

**Note:** If no such substring exists, return `-1`.

---

## Examples

### Example 1

**Input:**
`s = "aabacbebebe"`
`k = 3`

**Output:**
`7`

**Explanation:**
The longest substring with exactly 3 distinct characters is **"cbebebe"**, which includes `c`, `b`, and `e`.

---

### Example 2

**Input:**
`s = "aaaa"`
`k = 2`

**Output:**
`-1`

**Explanation:**
There is no substring with 2 distinct characters.

---

### Example 3

**Input:**
`s = "aabaaab"`
`k = 2`

**Output:**
`7`

**Explanation:**
The entire string **"aabaaab"** has exactly 2 distinct characters `a` and `b`, so the length is 7.

---

## Constraints

* `1 ≤ s.size() ≤ 10^5`
* `1 ≤ k ≤ 26`

---

## Approach (Sliding Window)

1. Use two pointers (`left` and `right`) to maintain a sliding window.
2. Use a hash map / frequency array to count characters in the current window.
3. Expand the window by moving `right`.
4. If distinct characters exceed `k`, shrink the window from the left.
5. When distinct characters equal `k`, update the maximum length.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(26)`
