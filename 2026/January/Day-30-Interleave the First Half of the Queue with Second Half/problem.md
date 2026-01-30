## Interleave the First Half of the Queue with Second Half

**Difficulty:** Medium  
**Accuracy:** 62.41%  
**Submissions:** 26K+  
**Points:** 4  
**Average Time:** 20m

---

### Problem Statement

Given a queue `q[]` of **even size**, your task is to rearrange the queue by **interleaving its first half with the second half**.

---

### What does Interleaving mean?

Interleaving is the process of mixing two sequences by alternating their elements **while preserving their relative order**.

In simpler words:

* Take the **first element** from the first half
* Then take the **first element** from the second half
* Then the **second element** from the first half
* Then the **second element** from the second half
* Continue this process until the queue is fully rearranged

---

### Examples

#### Example 1

```
Input:  q[] = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
```

**Explanation:**
First half = [2, 4]
Second half = [3, 1]
Interleaving → 2, 3, 4, 1

---

#### Example 2

```
Input:  q[] = [3, 5]
Output: [3, 5]
```

**Explanation:**
First half = [3]
Second half = [5]
Interleaving → 3, 5

---

### Constraints

* `1 ≤ queue.size() ≤ 10³`
* `1 ≤ queue[i] ≤ 10⁵`
* Queue size is always **even**

---

### Notes

* The relative order of elements **must be preserved**
* Only queue operations should be used
* No extra data structures unless required by logic

---

Happy Coding 🚀
