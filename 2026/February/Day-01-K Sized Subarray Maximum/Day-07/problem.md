# Max Sum in the Configuration

**Difficulty:** Medium  
**Accuracy:** 36.56%  
**Points:** 4

---

## Problem Statement

Given an integer array `arr[]`, find the **maximum value** of the expression:

```
Σ (i * arr[i])  for all 0 ≤ i < n
```

The only operation allowed is to **rotate** the array (clockwise or counter‑clockwise) any number of times.

---

## Examples

### Example 1

**Input:**

```
arr = [3, 1, 2, 8]
```

**Output:**

```
29
```

**Explanation:**

```
(3×0) + (1×1) + (2×2) + (8×3) = 29
```

This configuration gives the maximum value.

---

### Example 2

**Input:**

```
arr = [1, 2, 3]
```

**Output:**

```
8
```

**Explanation:**

```
(1×0) + (2×1) + (3×2) = 8
```

---

### Example 3

**Input:**

```
arr = [4, 13]
```

**Output:**

```
13
```

---

## Constraints

* `1 ≤ arr.size() ≤ 10^4`
* `1 ≤ arr[i] ≤ 20`

---

## Key Insight

Instead of recalculating the sum for every rotation (which would be **O(n²)**), we can use a **mathematical relation** to compute the next rotation value from the previous one in **O(1)** time.

Let:

* `R0` = value of Σ(i × arr[i]) for the initial array
* `arrSum` = sum of all elements in the array

Then for each rotation:

```
R(i) = R(i-1) + arrSum - n × lastElement
```

This allows us to solve the problem in **O(n)** time.

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Recommended Topics

* Array Rotation
* Mathematical Optimization
* Prefix Sum Concepts
