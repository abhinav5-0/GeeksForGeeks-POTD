# Union of Arrays with Duplicates

**Difficulty:** Easy
**Points:** 2

---

## Problem Statement

You are given two arrays `a[]` and `b[]`. Return the **Union** of both the arrays in any order.

The **Union** of two arrays is a collection of all **distinct elements** present in either of the arrays. If an element appears more than once in one or both arrays, it should be included **only once** in the result.

> **Note:**
>
> * Elements of `a[]` and `b[]` are not necessarily distinct.
> * You can return the union in any order, but the driver code will print the result in **sorted order**.

---

## Examples

### Example 1

**Input:**
`a[] = [1, 2, 3, 2, 1]`
`b[] = [3, 2, 2, 3, 3, 2]`

**Output:**
`[1, 2, 3]`

**Explanation:**
Union set of both the arrays will be 1, 2 and 3.

---

### Example 2

**Input:**
`a[] = [1, 2, 3]`
`b[] = [4, 5, 6]`

**Output:**
`[1, 2, 3, 4, 5, 6]`

**Explanation:**
Union set of both the arrays will be 1, 2, 3, 4, 5 and 6.

---

### Example 3

**Input:**
`a[] = [1, 2, 1, 1, 2]`
`b[] = [2, 2, 1, 2, 1]`

**Output:**
`[1, 2]`

**Explanation:**
Union set of both the arrays will be 1 and 2.

---

## Constraints

* `1 ≤ a.size(), b.size() ≤ 10^6`
* `0 ≤ a[i], b[i] ≤ 10^5`

---

## Approach

1. Use a **Set** data structure to store unique elements.
2. Insert all elements from array `a` into the set.
3. Insert all elements from array `b` into the set.
4. Convert the set into a list/vector and return it.

### Time Complexity

* **O(n + m)** where `n` and `m` are the sizes of arrays `a` and `b`.

### Space Complexity

* **O(n + m)** for storing unique elements in the set.
