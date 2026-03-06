# Smallest Window Containing All Characters

## Problem

Given two strings **s** and **p**, find the smallest substring in **s** that contains all characters of **p** (including duplicates).

If no such substring exists, return an empty string.

If multiple substrings of the same minimum length exist, return the one with the **least starting index**.

---

## Examples

### Example 1

**Input:**

```
s = "timetopractice"
p = "toc"
```

**Output:**

```
toprac
```

**Explanation:**
"toprac" is the smallest substring in which "toc" can be found.

---

### Example 2

**Input:**

```
s = "zoomlazapzo"
p = "oza"
```

**Output:**

```
apzo
```

**Explanation:**
"apzo" is the smallest substring in which "oza" can be found.

---

### Example 3

**Input:**

```
s = "zoom"
p = "zooe"
```

**Output:**

```
""
```

**Explanation:**
No substring is present containing all characters of p.

---

## Constraints

* 1 ≤ s.length(), p.length() ≤ 10^6
* s and p consist of lowercase English letters

---

## Approach (Sliding Window)

1. Store the frequency of characters of **p**.
2. Use two pointers (**left** and **right**) to create a sliding window on string **s**.
3. Expand the right pointer and include characters into the window.
4. When all characters of **p** are matched, try to shrink the window from the left.
5. Track the minimum window length.
6. Return the smallest substring found.

**Time Complexity:** O(N)

**Space Complexity:** O(1) (since alphabet size is constant)
