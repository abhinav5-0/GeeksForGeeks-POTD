## Problem Statement: Unique Number II

### Difficulty:
Medium

### Problem Description:
You are given an array `arr[]` containing `2 * n + 2` positive integers. In this array, `2 * n` numbers exist in pairs (i.e., each of those numbers appears exactly twice), while the remaining two numbers occur exactly once and are distinct.

Your task is to find these two unique numbers and return them in increasing order.

---

### Input Format:
- A single integer `t` denoting the number of test cases.
- For each test case:
  - A single line containing space-separated integers representing the array `arr[]`.

### Output Format:
- For each test case, print the two unique numbers in increasing order, separated by a space.

---

### Examples:

#### Example 1:
**Input:**
```
1
1 2 3 2 1 4
```
**Output:**
```
3 4
```
**Explanation:**
Numbers 3 and 4 occur exactly once.

#### Example 2:
**Input:**
```
1
2 1 3 2
```
**Output:**
```
1 3
```
**Explanation:**
Numbers 1 and 3 occur exactly once.

#### Example 3:
**Input:**
```
1
2 1 3 3
```
**Output:**
```
1 2
```
**Explanation:**
Numbers 1 and 2 occur exactly once.

---

### Constraints:
- `2 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 5 * 10^6`
- `arr.size()` is even

---

### Expected Time Complexity:
- O(n) per test case

### Expected Auxiliary Space:
- O(1)

---

### Approach:
- XOR all elements in the array. The result will be `x ^ y` where `x` and `y` are the two unique numbers.
- Find the rightmost set bit in `x ^ y`. This bit is different between `x` and `y`.
- Divide the numbers in the array into two groups based on that bit and XOR within each group to get `x` and `y`.
- Return them in sorted order.

