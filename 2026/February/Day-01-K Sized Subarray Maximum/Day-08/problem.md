# Maximum Product Subarray

**Difficulty:** Medium  
**Accuracy:** 18.09%  
**Points:** 4

---

## Problem Statement

Given an array `arr[]` that contains positive and negative integers (may contain `0` as well), find the **maximum product** that we can get from a **contiguous subarray** of `arr[]`.

> **Note:** It is guaranteed that the answer fits in a 32-bit integer.

---

## Examples

### Example 1

**Input:**

```
arr[] = [-2, 6, -3, -10, 0, 2]
```

**Output:**

```
180
```

**Explanation:**
The subarray with maximum product is `[6, -3, -10]`
Product = `6 × (-3) × (-10) = 180`

---

### Example 2

**Input:**

```
arr[] = [-1, -3, -10, 0, 6]
```

**Output:**

```
30
```

**Explanation:**
The subarray with maximum product is `[-3, -10]`
Product = `(-3) × (-10) = 30`

---

### Example 3

**Input:**

```
arr[] = [2, 3, 4]
```

**Output:**

```
24
```

**Explanation:**
All elements are positive, so the result is the product of all elements.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `-10 ≤ arr[i] ≤ 10`

---

## Key Idea

Because negative numbers can flip the sign of a product:

* We track both **maximum** and **minimum** product ending at each position.
* A negative number can turn a minimum product into a maximum.
* Zero resets the product chain.

This approach runs in **O(n)** time and **O(1)** extra space.

---

## Expected Approach

* Initialize:

  * `maxEndingHere`
  * `minEndingHere`
  * `ans`
* Traverse the array
* Update values carefully when encountering negative numbers or zero

---

> This problem is a classic variation of Kadane’s Algorithm adapted for products instead of sums.
