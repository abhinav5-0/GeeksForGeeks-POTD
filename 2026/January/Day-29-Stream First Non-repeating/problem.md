# Stream First Non-Repeating Character

**Difficulty:** Medium  
**Accuracy:** 31.65%  
**Points:** 4  
**Average Time:** 15m

---

## Problem Statement

Given a string `s` consisting of only lowercase alphabets, for each index `i` in the string `(0 ≤ i < n)`, find the **first non-repeating character** in the prefix `s[0..i]`.

If no such character exists, use `#`.

---

## Examples

### Example 1

**Input:**

```
s = "aabc"
```

**Output:**

```
a#bb
```

**Explanation:**

* i = 0 → `"a"` → first non-repeating = `a`
* i = 1 → `"aa"` → no non-repeating → `#`
* i = 2 → `"aab"` → first non-repeating = `b`
* i = 3 → `"aabc"` → non-repeating are `b`, `c` → `b` appeared first

---

### Example 2

**Input:**

```
s = "bb"
```

**Output:**

```
b#
```

**Explanation:**

* i = 0 → `"b"` → first non-repeating = `b`
* i = 1 → `"bb"` → no non-repeating → `#`

---

## Constraints

* `1 ≤ s.size() ≤ 10^5`
* `s` contains only lowercase English letters

---

## Approach (Intuition)

We process the string **character by character (stream)**.

* Maintain a **frequency array** to track how many times each character appears.
* Maintain a **queue** to keep characters in the order they appear.

### Steps:

1. For every character `ch` in the string:

   * Increase its frequency
   * Push it into the queue
2. While the front of the queue has frequency > 1, pop it
3. If queue is empty → append `#` to answer
4. Else → append `queue.front()`

---

## Expected Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` (since only 26 lowercase letters)

---

## Notes

* This is a classic **queue + frequency** problem
* Very important for understanding **stream processing** and **real-time character tracking**

---

✅ Ideal problem to strengthen **data structures basics (Queue + Array)**
