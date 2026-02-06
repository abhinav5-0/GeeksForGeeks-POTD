## Happiest Triplet

### Difficulty

Medium

### Problem Statement

You are given three arrays **a[]**, **b[]**, **c[]** of the same size. Your task is to find a triplet such that:

* The triplet contains **one element from each array**.
* The value **(maximum − minimum)** among the three chosen numbers is **minimum among all possible triplets**.

This triplet is called the **happiest triplet**.

### Tie-Break Rule

If there are **two or more triplets** with the same minimum difference, choose the one with the **smallest sum of its elements**.

Finally, **print the triplet in decreasing order**.

---

### Example 1

**Input:**

* a = [5, 2, 8]
* b = [10, 7, 12]
* c = [9, 14, 6]

**Output:**

```
[7, 6, 5]
```

**Explanation:**
The triplet (5, 7, 6) has:

* max = 7
* min = 5
* difference = 2 (minimum possible)

---

### Example 2

**Input:**

* a = [15, 12, 18, 9]
* b = [10, 17, 13, 8]
* c = [14, 16, 11, 5]

**Output:**

```
[11, 10, 9]
```

**Explanation:**
Multiple triplets have the same minimum difference, but (11, 10, 9) has the **smallest sum**, so it is chosen.

---

### Constraints

* 1 ≤ a.size(), b.size(), c.size() ≤ 10⁵
* 1 ≤ a[i], b[i], c[i] ≤ 10⁵

---

### Expected Approach (Hint)

* Sort all three arrays
* Use a **three-pointer technique** to efficiently minimize `(max − min)`
* Track the best triplet and apply tie-break using sum

---

### Output Format

Return the happiest triplet in **decreasing order**.
