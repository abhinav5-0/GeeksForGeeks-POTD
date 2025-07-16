### Problem: Count Numbers with Exactly 9 Divisors

**Difficulty:** Medium  
**Points:** 4  
**Constraints:** `1 ≤ n ≤ 10^9`

---

### Problem Statement

Given a positive integer `n`, you need to count how many numbers less than or equal to `n` have **exactly 9 positive divisors**.

---

### Input:
- A single integer `n` representing the upper bound.

### Output:
- Return a single integer — the count of numbers less than or equal to `n` that have exactly 9 divisors.

---

### Examples

#### Example 1:
**Input:**
``` 
n = 100
```
**Output:**
```
2
```
**Explanation:**
Numbers with exactly 9 divisors: 36 and 100

#### Example 2:
**Input:**
``` 
n = 200
```
**Output:**
```
3
```
**Explanation:**
Numbers with exactly 9 divisors: 36, 100, 196

---

### Mathematical Insight
A number has exactly 9 divisors if:
- It is of the form `p^8` where `p` is a prime number. (Since divisors = 8+1 = 9)
- It is of the form `p1^2 * p2^2` where `p1` and `p2` are distinct prime numbers. (Divisors = (2+1)(2+1) = 9)

---

### Efficient Approach
1. Generate all primes up to \( \sqrt{n} \) using Sieve of Eratosthenes.
2. Count:
   - All primes `p` such that `p^8 <= n`
   - All distinct pairs of primes `(p1, p2)` such that `p1^2 * p2^2 <= n`

---

### Tags
`Math` `Number Theory` `Prime Numbers` `Divisors` `Sieve`
