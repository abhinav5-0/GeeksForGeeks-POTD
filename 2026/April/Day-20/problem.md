# Count Derangements

## 🧩 Problem Statement

Given a number `n`, find the total number of **derangements** of elements from `1` to `n`.

A **Derangement** is a permutation of elements such that no element appears in its original position.

* 1 should not be at position 1
* 2 should not be at position 2
* and so on...

📌 Example: `[5, 3, 2, 1, 4]` is a derangement of first 5 elements.

---

## 📝 Note

* The answer will always fit into a **32-bit integer**.

---

## 🔍 Examples

### Example 1

```
Input: n = 2
Output: 1
```

**Explanation:**
For `[1, 2]`, there is only one derangement → `[2, 1]`

---

### Example 2

```
Input: n = 3
Output: 2
```

**Explanation:**
For `[1, 2, 3]`, the derangements are:

* `[2, 3, 1]`
* `[3, 1, 2]`

---

## ⚙️ Constraints

* `1 ≤ n ≤ 12`

---

## 💡 Approach

Derangements follow this recurrence relation:

```
D(n) = (n - 1) * (D(n - 1) + D(n - 2))
```

### Base Cases:

* `D(1) = 0`
* `D(2) = 1`

---

## 🚀 Algorithm

1. Handle base cases.
2. Use recursion or dynamic programming.
3. Build result using the recurrence relation.

---

## 🧠 Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` (if optimized)

---

## 📌 Summary

* Derangement means **no element stays in original position**.
* Use the recurrence formula for efficient computation.
* Works well for `n ≤ 12`.
