## Problem Statement: Maximum XOR of Two Numbers in an Array

### Difficulty:
Medium

### Accuracy:
50.0%

### Submissions:
13K+

### Points:
4

---

### Description:
Given an array `arr[]` of non-negative integers of size `n`, find the maximum possible XOR value between any two numbers present in the array.

---

### Input Format:
- An integer `t` representing the number of test cases.
- For each test case:
  - An integer `n` denoting the number of elements in the array.
  - A list of `n` non-negative integers.

### Output Format:
- For each test case, output a single integer — the maximum XOR value of any two numbers in the array.

---

### Examples:
**Input:**
```
arr[] = [25, 10, 2, 8, 5, 3]
```
**Output:**
```
28
```
**Explanation:**
Maximum possible XOR is `5 ^ 25 = 28`

**Input:**
```
arr[] = [1, 2, 3, 4, 5, 6, 7]
```
**Output:**
```
7
```
**Explanation:**
Maximum possible XOR is `1 ^ 6 = 7`

---

### Constraints:
- $2 \leq \text{arr.size()} \leq 5 \times 10^4$
- $1 \leq \text{arr}[i] \leq 10^6$

---

### Suggested Approach:
Use a Trie-based approach to efficiently compute the maximum XOR. Insert binary representations of numbers into the Trie and for each number, try to find the best complement in the Trie that gives the maximum XOR value.

