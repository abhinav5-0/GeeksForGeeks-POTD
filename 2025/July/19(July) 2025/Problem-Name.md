# Count Unique Vowel Strings

**Difficulty:** Medium
**Accuracy:** 50.99%
**Submissions:** 11K+
**Points:** 4

---

## Problem Statement

You are given a lowercase string `s`. Determine the total number of **distinct strings** that can be formed using the following rules:

1. Identify all **unique vowels** (`a, e, i, o, u`) present in the string.
2. For each distinct vowel, choose **exactly one of its occurrences** from `s`.

   * If a vowel appears multiple times, **each occurrence represents a unique selection choice**.
3. Generate all **possible permutations** of the selected vowels.

   * Each unique arrangement counts as a distinct string.
4. Return the **total number of such distinct strings**.

---

## Input

* A lowercase string `s`
* `1 ≤ s.size() ≤ 100`

---

## Output

* An integer denoting the number of distinct vowel strings that can be formed.

---

## Examples

### Example 1

**Input:**

```
s = "aeiou"
```

**Output:**

```
120
```

**Explanation:**
Each vowel appears once. The number of different strings is `5! = 120`.

---

### Example 2

**Input:**

```
s = "ae"
```

**Output:**

```
2
```

**Explanation:**
Pick `'a'` and `'e'`, make all permutations → `"ae"`, `"ea"`.

---

### Example 3

**Input:**

```
s = "aacidf"
```

**Output:**

```
4
```

**Explanation:**
Vowels in `s` are `'a'` (2 times) and `'i'` (1 time).

* Pick one `'a'` in 2 ways, pick `'i'` in 1 way: `2 × 1 = 2`
* Permutations of 2 vowels = `2! = 2`
* Total = `2 × 2 = 4`

---

## Constraints

* `1 ≤ s.length ≤ 100`
* `s` contains only lowercase English letters

---

## Tags

* Strings
* Permutations
* Combinatorics
* Frequency Count
