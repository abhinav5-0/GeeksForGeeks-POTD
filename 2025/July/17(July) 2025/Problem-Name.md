## Problem: Power of k in Factorial of n

**Difficulty:** Medium
**Accuracy:** 51.2%
**Submissions:** 11K+
**Points:** 4

### Problem Statement:

Given two positive integers `n` and `k`, determine the highest value of `x` such that `k^x` divides `n!` (n factorial) completely, i.e., `n! % (k^x) == 0`.

### Examples:

**Input:**

```
n = 7, k = 2
```

**Output:**

```
4
```

**Explanation:**

```
7! = 5040, and 2^4 = 16 is the highest power of 2 that divides 5040.
```

**Input:**

```
n = 10, k = 9
```

**Output:**

```
2
```

**Explanation:**

```
10! = 3628800, and 9^2 = 81 is the highest power of 9 that divides 3628800.
```

### Constraints:

* 1 ≤ n ≤ 10^5
* 2 ≤ k ≤ 10^5

### Function Signature:

```cpp
class Solution {
  public:
    int maxKPower(int n, int k);
};
```

### Approach:

1. **Prime Factorize** `k` into the form `p1^a1 * p2^a2 * ... * pn^an`.
2. For each prime factor `pi`:

   * Count how many times `pi` appears in `n!` using the formula: `n/pi + n/pi^2 + n/pi^3 + ...`
   * Divide this count by `ai` (the exponent of `pi` in the factorization of `k`).
3. The minimum of all such values for all prime factors is the highest power `x` such that `k^x` divides `n!`.
