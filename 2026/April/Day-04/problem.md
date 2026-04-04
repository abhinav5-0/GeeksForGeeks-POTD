# Gray Code

**Difficulty:** Medium
**Accuracy:** 60.49%
**Submissions:** 16K+
**Points:** 4

---

## Problem Statement

Given a number **n**, generate bit patterns from **0** to **2^n - 1** such that successive patterns differ by only **one bit**.

A Gray code sequence must **begin with 0**.

---

## Examples

### Example 1

**Input:**

```
n = 2
```

**Output:**

```
["00", "01", "11", "10"]
```

**Explanation:**

* 00 and 01 differ by one bit.
* 01 and 11 differ by one bit.
* 11 and 10 also differ by one bit.

---

### Example 2

**Input:**

```
n = 3
```

**Output:**

```
["000", "001", "011", "010", "110", "111", "101", "100"]
```

**Explanation:**

* 000 and 001 differ by one bit.
* 001 and 011 differ by one bit.
* 011 and 010 differ by one bit.
* Similarly, every successive pattern differs by one bit.

---

## Constraints

```
1 ≤ n ≤ 16
```

---

## Approach

* Start with base case: `n = 1 → ["0", "1"]`
* For each next level:

  * Take previous result
  * Prefix `0` to original order
  * Prefix `1` to reversed order
* Combine both

---

## Pseudocode

```
res = ["0", "1"]
for i from 2 to n:
    temp = []
    for x in res:
        temp.push("0" + x)
    for x in reverse(res):
        temp.push("1" + x)
    res = temp
return res
```

---

## Complexity Analysis

* **Time Complexity:** O(2^n)
* **Space Complexity:** O(2^n)

---

## Notes

* Gray Code ensures only one bit changes between consecutive values.
* Widely used in digital communication and error correction.
