# Find Kth Rotation

## Problem Statement

You are given an **increasing sorted array** `arr[]` of **distinct integers**, which has been **right-rotated `k` times**.

Your task is to **find the value of `k`** (number of right rotations).

---

## Understanding Right Rotation

A right rotation shifts elements to the **right**, moving the **last element to the front**.

### Example

Original array:

```
[2, 4, 6, 9]
```

After 1 right rotation:

```
[9, 2, 4, 6]
```

After 2 right rotations:

```
[6, 9, 2, 4]
```

---

## Key Observation

* In a sorted array, the **smallest element** is at index `0`.
* After rotation, the **index of the minimum element** tells us how many times the array was rotated.

### So:

```
K = index of minimum element
```

---

## Examples

### Example 1

**Input:**

```
arr = [5, 1, 2, 3, 4]
```

**Output:**

```
1
```

**Explanation:**
The original array was `[1, 2, 3, 4, 5]`. It was rotated **once to the right**.

---

### Example 2

**Input:**

```
arr = [1, 2, 3, 4, 5]
```

**Output:**

```
0
```

**Explanation:**
The array is already sorted, so **no rotation**.

---

## Approach

1. Traverse the array
2. Find the **index of the minimum element**
3. Return that index

---

## Time & Space Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^7`

---

✅ This method works efficiently within given constraints and is easy to implement.
