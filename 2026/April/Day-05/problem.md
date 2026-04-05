# 🎯 Target Sum

**Difficulty:** Medium
**Accuracy:** 31.52%
**Submissions:** 45K+
**Points:** 4

---

## 📝 Problem Statement

Given an array of integers `arr[]` and an integer `target`, we need to build an **expression** out of `arr[]` by adding one of the symbols `'+'` or `'-'` before each integer and concatenate all the integers.

Return the number of different **expressions** that can be built, which evaluates to the given `target`.

---

## 📌 Note

* An expression is considered different from another if the placement of `'+'` and `'-'` operators differs, even if the resulting value is the same.

---

## 📥 Examples

### Example 1

```
Input: arr[] = [1, 1, 1, 1, 1], target = 3
Output: 5
```

**Explanation:** There are 5 ways to assign symbols:

```
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

---

### Example 2

```
Input: arr[] = [1, 2, 3], target = 2
Output: 1
```

**Explanation:**

```
+1 - 2 + 3 = 2
```

---

## 🔒 Constraints

* `1 ≤ arr.size() ≤ 50`
* `1 ≤ arr[i] ≤ 20`
* `0 ≤ sum(arr) ≤ 1000`
* `-1000 ≤ target ≤ 1000`

---

## 💡 Approach (Hint)

This problem can be solved using:

* Recursion + Memoization
* Dynamic Programming (Subset Sum Transformation)

### Key Idea:

Let:

* Sum of all elements = `S`
* Required target = `T`

We convert the problem into finding subsets such that:

```
P - N = T
P + N = S
```

Solving:

```
P = (S + T) / 2
```

Now the problem reduces to **counting subsets with sum = P**.

---

## 🚀 Complexity

* **Time Complexity:** `O(N * S)`
* **Space Complexity:** `O(S)`

---

## ✅ Summary

* Convert sign problem → subset sum problem
* Count number of subsets with required sum
* Use DP for optimization

---

✨ Happy Coding!
