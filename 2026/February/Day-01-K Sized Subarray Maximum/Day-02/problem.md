# Max Circular Subarray Sum

**Difficulty:** Hard
**Accuracy:** 29.37%
**Submissions:** 193K+
**Points:** 8
**Average Time:** 25m

---

## Problem Statement

You are given a **circular array** `arr[]` of integers. Your task is to find the **maximum possible sum of a non-empty subarray**.

In a circular array, the subarray can:

* Be a normal subarray (no wrapping), or
* Start at the end of the array and wrap around to the beginning.

Return the **maximum non-empty subarray sum**, considering both **wrapping** and **non-wrapping** cases.

---

## Examples

### Example 1

**Input:**

```
arr[] = [8, -8, 9, -9, 10, -11, 12]
```

**Output:**

```
22
```

**Explanation:**
Starting from the last element (12) and moving circularly:

```
12 + 8 - 8 + 9 - 9 + 10 = 22
```

---

### Example 2

**Input:**

```
arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
```

**Output:**

```
23
```

**Explanation:**
Maximum circular subarray:

```
[7, 6, 5, -4, -1, 10]
```

Sum = 23

---

### Example 3

**Input:**

```
arr[] = [5, -2, 3, 4]
```

**Output:**

```
12
```

**Explanation:**
Circular subarray:

```
[3, 4, 5]
```

Sum = 12

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `-10^4 ≤ arr[i] ≤ 10^4`

---

## Expected Time & Space Complexity

* **Time Complexity:** `O(n)`
* **Auxiliary Space:** `O(1)`

---

## Key Insight

The maximum circular subarray sum is the maximum of:

1. **Normal maximum subarray sum** (Kadane’s Algorithm)
2. **Total array sum - minimum subarray sum** (for wrapping case)

⚠️ Special Case: If all elements are negative, return the **maximum element** (normal Kadane result).

---

## Function Signature (C++)

```cpp
int maxCircularSum(vector<int> &arr);
```

---

✅ This problem is a classic application of **Kadane’s Algorithm** with a smart twist for circular arrays.
