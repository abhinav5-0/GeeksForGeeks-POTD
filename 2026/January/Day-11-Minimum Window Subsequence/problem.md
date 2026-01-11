# Minimum Window Subsequence

## Problem Summary

You are given two strings:

* **s1** (length up to `10^4`)
* **s2** (length up to `50`)

Your task is to find the **smallest substring of s1** such that **s2 appears as a subsequence** inside that substring.

### Important Points

* **Subsequence** means characters appear in the same order, **not necessarily contiguous**.
* If multiple substrings have the same minimum length, return the **leftmost** one.
* If no such substring exists, return an **empty string**.

---

## Example

**Input**

```
s1 = "abcdebdde"
s2 = "bde"
```

**Output**

```
"bcde"
```

Explanation:

* "bcde" and "bdde" both contain `b → d → e` as a subsequence
* "bcde" is smaller and appears first

---

## Key Idea (Beginner Friendly)

We scan **s1** and try to match **s2** as a subsequence.

### Strategy

1. Move forward in `s1` to **match all characters of s2** in order
2. Once matched, move **backward** to shrink the window as much as possible
3. Keep track of the **minimum window** found
4. Continue searching to find a better (smaller or earlier) window

This is a **two-pointer greedy approach**.

---

## Why This Works

* `s2` is very small (≤ 50), so subsequence matching is fast
* Forward scan ensures order
* Backward scan minimizes window size

**Time Complexity:** `O(n × m)` (worst case)

* `n = len(s1)`
* `m = len(s2)`

This works efficiently within constraints.

---

## Edge Cases

* `s2` not present as subsequence → return `""`
* Exact match of characters
* Multiple valid windows → return leftmost

---

## Final Notes

* This problem is **NOT sliding window** like minimum window substring
* Order matters, contiguity does NOT
* Very common interview question 🔥

If this explanation helped you understand the logic, please ⭐ star / 👍 upvote — it motivates a lot!
