# Trail of Ones

**Difficulty:** Medium
**Accuracy:** 51.16%
**Submissions:** 37K+
**Points:** 4

## Problem Statement

Given an integer `n`, the task is to count the number of binary strings of length `n` that contain **at least one pair of consecutive 1's**.

**Note:** A binary string is a sequence made up of only 0's and 1's.

---

## Examples

### Example 1:

**Input:**

```
n = 2
```

**Output:**

```
1
```

**Explanation:**
There are 4 binary strings of length 2: `00`, `01`, `10`, and `11`. Only the string `11` contains consecutive 1's.

### Example 2:

**Input:**

```
n = 3
```

**Output:**

```
3
```

**Explanation:**
There are 8 binary strings of length 3: `000`, `001`, `010`, `011`, `100`, `101`, `110`, `111`. The strings `011`, `110`, and `111` contain consecutive 1's.

### Example 3:

**Input:**

```
n = 5
```

**Output:**

```
19
```

**Explanation:**
There are 32 binary strings of length 5. Out of these, 13 strings do **not** contain any consecutive 1's. So, the number of strings that **do** contain at least one pair of consecutive 1's = `32 - 13 = 19`.

---

## Constraints

* 2 ≤ n ≤ 30

---

## Approach

1. Total number of binary strings of length `n` is `2^n`.
2. Subtract the number of binary strings **without** any pair of consecutive 1's.

Let:

* `a[i]` = number of valid strings of length `i` ending in `0`.
* `b[i]` = number of valid strings of length `i` ending in `1`.

### Recurrence:

* `a[i] = a[i-1] + b[i-1]` (can append `0` to both)
* `b[i] = a[i-1]` (can only append `1` to string ending in `0`)

Then,

* `valid = a[n] + b[n]`
* `answer = 2^n - valid`

---

## C++ Function Signature

```cpp
class Solution {
  public:
    int countConsec(int n);
};
```
