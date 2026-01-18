## Next Element with Greater Frequency

### Problem Statement

Given an array `arr[]` of integers, for each element find the **first element to its right** that has a **higher frequency** than the current element.

* If no such element exists, return `-1` for that position.
* Frequency means the total count of that value in the entire array.

---

### Examples

**Example 1**

```
Input:  [2, 1, 1, 3, 2, 1]
Output: [1, -1, -1, 2, 1, -1]
```

Frequencies:

* 1 → 3 times
* 2 → 2 times
* 3 → 1 time

**Example 2**

```
Input:  [5, 1, 5, 6, 6]
Output: [-1, 5, -1, -1, -1]
```

Frequencies:

* 1 → 1 time
* 5 → 2 times
* 6 → 2 times

---

### Approach (Efficient – O(n))

This problem is similar to **Next Greater Element**, but instead of comparing values, we compare **frequencies**.

#### Steps:

1. **Frequency Map**
   Count the frequency of each element using a hash map.

2. **Stack-Based Traversal (Right to Left)**

   * Use a stack to keep indices of elements.
   * Traverse the array from right to left.
   * Pop elements from the stack while their frequency is **less than or equal** to the current element's frequency.
   * The top of the stack (if any) is the answer for the current element.

3. **Push Current Index** onto the stack.

---

### Why Stack Works Here

* Each element is pushed and popped **at most once**.
* This guarantees **O(n)** time complexity.

---

### Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (frequency map + stack)

---

### Key Observations

* Frequencies are global, not subarray-based.
* We compare **frequency**, not the element value.
* If two elements have equal frequency, it is **not considered greater**.

---

### Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^5`

---

### Related Problems

* Next Greater Element
* Next Smaller Element
* Stock Span Problem

---

This problem is a classic example of how **monotonic stacks** can be adapted beyond simple value comparisons.
