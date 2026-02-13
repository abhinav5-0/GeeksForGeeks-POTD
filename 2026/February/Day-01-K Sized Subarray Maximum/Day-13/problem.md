# All Numbers With Specific Difference

**Difficulty:** Hard
**Accuracy:** 50.0%
**Submissions:** 15K+
**Points:** 8

---

## Problem Statement

Given a positive number **n** and a number **d**, find the **count** of positive numbers smaller than or equal to **n** such that the difference between the number and the sum of its digits is greater than or equal to the given value **d**.

Formally, count numbers `x` such that:

```
x ≤ n
x - (sum of digits of x) ≥ d
```

---

## Examples

### Example 1

**Input:**

```
n = 13
d = 2
```

**Output:**

```
4
```

**Explanation:**
There are 4 numbers satisfying the condition.
These are: `10, 11, 12, 13`

---

### Example 2

**Input:**

```
n = 14
d = 3
```

**Output:**

```
5
```

**Explanation:**
There are 5 numbers satisfying the condition.
These are: `10, 11, 12, 13, 14`

---

## Constraints

```
1 ≤ n ≤ 10^9
1 ≤ d ≤ 10^9
```

---

## Function Signature (C++)

```cpp
class Solution {
public:
    int getCount(int n, int d) {
        // code here
    }
};
```

---

## Notes

* The sum of digits of a number is obtained by adding all its digits.
* Efficient approaches are required due to large constraints (up to 10^9).
* Brute force may not work within time limits for large inputs.
