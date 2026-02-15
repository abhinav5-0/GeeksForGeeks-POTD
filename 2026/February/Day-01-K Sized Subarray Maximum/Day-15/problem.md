# Chocolate Distribution Problem

## Difficulty: Easy

**Accuracy:** 49.91%
**Submissions:** 269K+
**Points:** 2
**Average Time:** 15m

---

## Problem Statement

Given an array `arr[]` of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are `m` students. The task is to distribute chocolate packets among `m` students such that:

1. Each student gets **exactly one packet**.
2. The difference between the maximum number of chocolates given to a student and the minimum number of chocolates given to a student is minimum.

Return the **minimum possible difference**.

---

## Examples

### Example 1

**Input:**

```
arr = [3, 4, 1, 9, 56, 7, 9, 12]
m = 5
```

**Output:**

```
6
```

**Explanation:**
The minimum difference between maximum and minimum chocolates is `9 - 3 = 6` by choosing the following 5 packets:

```
[3, 4, 7, 9, 9]
```

---

### Example 2

**Input:**

```
arr = [7, 3, 2, 4, 9, 12, 56]
m = 3
```

**Output:**

```
2
```

**Explanation:**
The minimum difference is `4 - 2 = 2` by choosing:

```
[2, 3, 4]
```

---

### Example 3

**Input:**

```
arr = [3, 4, 1, 9, 56]
m = 5
```

**Output:**

```
55
```

**Explanation:**
With 5 packets for 5 students, each student receives one packet.
Difference = `56 - 1 = 55`

---

## Constraints

* `1 ≤ m ≤ arr.size ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^9`

---

## Expected Approach (Hint)

* Sort the array.
* Use a sliding window of size `m`.
* Compute the difference between the first and last element of each window.
* Return the minimum difference found.

**Time Complexity:** `O(n log n)`
**Space Complexity:** `O(1)` (excluding sorting space)
