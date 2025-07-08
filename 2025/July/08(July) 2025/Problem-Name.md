# Problem: Next Element with Greater Frequency

**Difficulty:** Medium
**Accuracy:** 60.4%
**Submissions:** 17K+
**Points:** 4

## Problem Statement

Given an array `arr[]` of integers, for each element, find the closest (distance-wise) element to its right that has a **higher frequency** than the current element. If no such element exists, return `-1` for that position.

### Input

* An integer array `arr[]` of size `n` (1 <= n <= 10^5).
* 1 <= arr\[i] <= 10^5

### Output

* An array of size `n` where each index contains the next element with greater frequency. If no such element exists, return `-1`.

## Examples

### Example 1

**Input:**

```
arr = [2, 1, 1, 3, 2, 1]
```

**Output:**

```
[1, -1, -1, 2, 1, -1]
```

**Explanation:**

* Frequencies: 1 → 3 times, 2 → 2 times, 3 → 1 time.
* For arr\[0] = 2, the next element 1 has a higher frequency → 1.
* For arr\[1] and arr\[2], no element to the right has a higher frequency → -1.
* For arr\[3] = 3, the next element 2 has a higher frequency → 2.
* For arr\[4] = 2, the next element 1 has a higher frequency → 1.
* For arr\[5] = 1, no elements to the right → -1.

### Example 2

**Input:**

```
arr = [5, 1, 5, 6, 6]
```

**Output:**

```
[-1, 5, -1, -1, -1]
```

**Explanation:**

* Frequencies: 1 → 1 time, 5 → 2 times, 6 → 2 times.
* For arr\[0] and arr\[2], no element to the right has a higher frequency → -1.
* For arr\[1] = 1, the next element 5 has a higher frequency → 5.
* For arr\[3] and arr\[4], no element to the right has a higher frequency → -1.

## Constraints

* 1 <= arr.size() <= 10^5
* 1 <= arr\[i] <= 10^5

## Expected Time Complexity

* O(n) time using stack and hash map

## Tags

Array, Stack, Hashing
