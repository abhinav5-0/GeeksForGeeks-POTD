# Painting the Fence

## 🧩 Problem Statement

Given a fence with **n** posts and **k** colours, find the number of ways to paint the fence such that **not more than two consecutive posts have the same colour**.

> The answer is guaranteed to fit within a 32-bit integer.

---

## 📥 Input

* Two integers:

  * `n` → number of posts
  * `k` → number of colours

## 📤 Output

* Return the total number of valid ways to paint the fence.

---

## 💡 Examples

### Example 1

```
Input: n = 3, k = 2
Output: 6
```

**Explanation:**
Possible combinations using colours R and B:

* RRB
* RBR
* RBB
* BRR
* BRB
* BBR

---

### Example 2

```
Input: n = 2, k = 4
Output: 16
```

**Explanation:**

* First post: 4 choices
* Second post: 4 choices
* Total = 4 × 4 = 16

---

## ⚙️ Constraints

* `1 ≤ n ≤ 300`
* `1 ≤ k ≤ 10^5`

---

## 🚀 Approach (Dynamic Programming)

We track two states:

* `same` → ways where last two posts have same colour
* `diff` → ways where last two posts have different colours

### Recurrence:

* For first post:

  * `same = 0`
  * `diff = k`

* For second post:

  * `same = k`
  * `diff = k * (k - 1)`

* For i-th post:

  * `same = diff`
  * `diff = (same + diff) * (k - 1)`

### Final Answer:

```
result = same + diff
```

---

## ⏱️ Complexity

* Time: `O(n)`
* Space: `O(1)`

---

## 🧪 Edge Cases

* `n = 1` → answer = `k`
* `n = 2` → answer = `k * k`

---

## 🏁 Summary

This is a classic DP problem where we ensure no more than two consecutive posts have the same color by tracking transitions between same and different color states.
