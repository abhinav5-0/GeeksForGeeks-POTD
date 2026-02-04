
# Last Moment Before All Ants Fall Out

**Difficulty:** Medium
**Accuracy:** ~62%
**Points:** 4

---

## 🐜 Problem Statement

We have a wooden plank of length **`n` units**.

Some ants are walking on the plank:

* Each ant moves at **1 unit per second**.
* Some ants move **left**, some move **right**.
* When two ants meet, they **change directions** (this is equivalent to ants passing through each other).
* When an ant reaches either end of the plank (position `0` or `n`), it **falls off immediately**.

You are given:

* An integer `n`
* Two integer arrays:

  * `left[]` → positions of ants moving left
  * `right[]` → positions of ants moving right

### 🎯 Task

Return the **time when the last ant falls off the plank**.

---

## 🧠 Key Insight (Very Important)

When ants collide and reverse direction, the **overall result is the same as if they passed through each other**.

👉 So we **don’t need to simulate collisions**.

We only calculate:

* Time for left-moving ants to fall: `position`
* Time for right-moving ants to fall: `n - position`

The answer is the **maximum** of all these times.

---

## ✨ Examples

### Example 1

**Input:**

```
n = 4
left = [2]
right = [0, 1, 3]
```

**Output:**

```
4
```

**Explanation:** The last ant falls off at `t = 4`.

---

### Example 2

**Input:**

```
n = 4
left = []
right = [0, 1, 2, 3, 4]
```

**Output:**

```
4
```

**Explanation:** All ants move right. Ant at position `0` takes `4` seconds.

---

### Example 3

**Input:**

```
n = 3
left = [0]
right = [3]
```

**Output:**

```
0
```

**Explanation:** Ants are already at the edge and fall immediately.

---

## 📌 Constraints

* `1 ≤ n ≤ 10^5`
* `0 ≤ left.length, right.length ≤ n + 1`
* All values in `left` and `right` are **unique**
* An ant appears in **only one** of the arrays

---

## 🧮 Algorithm

1. Initialize `ans = 0`
2. For each position `x` in `left`:

   * `ans = max(ans, x)`
3. For each position `x` in `right`:

   * `ans = max(ans, n - x)`
4. Return `ans`

---

## ⏱ Time & Space Complexity

* **Time:** `O(L + R)`
* **Space:** `O(1)` (excluding input)

---

## 🚀 Summary

* Ignore collisions ❌
* Just compute **farthest fall time** ✅
* Simple, clean, and efficient 💯

Happy coding 🧑‍💻🐜
