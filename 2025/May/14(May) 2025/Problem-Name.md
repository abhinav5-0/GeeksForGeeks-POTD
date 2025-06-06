## Problem: Look and Say Pattern

**Difficulty:** Medium
**Accuracy:** 62.54%
**Submissions:** 34K+
**Points:** 4

### Problem Statement

Given an integer `n`, return the **nth row** of the following look-and-say pattern:

```
1
11
21
1211
111221
```

### Look-and-Say Pattern Explanation

To generate a member of the sequence from the previous member:

* Read off the digits of the previous member.
* Count the number of digits in **groups of the same digit**.

#### Example Steps:

* `1` is read off as "one 1" → `11`
* `11` is read off as "two 1s" → `21`
* `21` is read off as "one 2, then one 1" → `1211`
* `1211` is read off as "one 1, one 2, then two 1s" → `111221`
* `111221` is read off as "three 1s, two 2s, one 1" → `312211`

### Examples

#### Example 1:

**Input:**

```
n = 5
```

**Output:**

```
111221
```

**Explanation:**
The 5th row of the pattern is `111221`.

#### Example 2:

**Input:**

```
n = 3
```

**Output:**

```
21
```

**Explanation:**
The 3rd row of the pattern is `21`.

### Constraints

* `1 ≤ n ≤ 30`
