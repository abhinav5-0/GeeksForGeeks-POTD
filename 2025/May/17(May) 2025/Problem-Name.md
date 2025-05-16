## Problem: Sort the Array After Applying a Quadratic Equation

### Difficulty:
Easy

### Problem Statement:
Given an integer array `arr[]` sorted in ascending order, and three integers: `A`, `B`, and `C`, your task is to apply the quadratic function:

```
f(x) = A * x^2 + B * x + C
```

to each element `x` in the array and return the resulting array in **sorted order**.

---

### Examples:

**Input:**
```
arr[] = [-4, -2, 0, 2, 4]
A = 1, B = 3, C = 5
```
**Output:**
```
[3, 5, 9, 15, 33]
```
**Explanation:**
After applying f(x) = x^2 + 3x + 5: [9, 3, 5, 15, 33] → Sorted: [3, 5, 9, 15, 33]

**Input:**
```
arr[] = [-3, -1, 2, 4]
A = -1, B = 0, C = 0
```
**Output:**
```
[-16, -9, -4, -1]
```
**Explanation:**
After applying f(x) = -x^2: [-9, -1, -4, -16] → Sorted: [-16, -9, -4, -1]

---

### Constraints:
- 1 ≤ arr.size() ≤ 10^6
- -10^3 ≤ arr[i], A, B, C ≤ 10^3

---

### Approach:
1. The given array is already sorted.
2. Apply the quadratic equation `f(x) = Ax^2 + Bx + C` to each element.
3. Depending on the sign of A:
   - If A >= 0: The result forms a U-shape (higher values at the ends).
   - If A < 0: The result forms an inverted U-shape (lower values at the ends).
4. Use a two-pointer approach to fill the result array from either start or end, depending on A's sign.

### Time Complexity:
- **O(N)**: Linear time using two pointers.

### Space Complexity:
- **O(N)**: For the result array.

---

### Tags:
- Arrays
- Two Pointers
- Sorting
- Mathematical Transformation
- Quadratic Equations
