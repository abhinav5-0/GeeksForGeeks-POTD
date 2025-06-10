# Problem: Count Distinct Strings After One Swap

## Difficulty: Medium

### Problem Statement

You are given a string `s` consisting of lowercase English letters. You are allowed to perform **exactly one swap** of two **different indices** `(i < j)` in the string.

Your task is to determine how many **distinct strings** can be obtained by such a single swap.

### Input

* A string `s` of length `n` (2 <= n <= 10^4)

### Output

* An integer representing the number of distinct strings that can be obtained after exactly one swap of two different indices.

### Constraints

* The string contains only lowercase English letters.
* 2 ≤ s.length ≤ 10^4

### Examples

#### Example 1:

**Input:**

```
s = "geek"
```

**Output:**

```
6
```

**Explanation:**
The distinct strings that can be formed are: "egek", "eegk", "geke", "gkee", "keeg", and "geek".

#### Example 2:

**Input:**

```
s = "aaaa"
```

**Output:**

```
1
```

**Explanation:**
All characters are the same, any swap results in the same string.

#### Example 3:

**Input:**

```
s = "jej"
```

**Output:**

```
2
```

**Explanation:**
Distinct strings after one swap are: "ejj" and "jje".

### Optimal Solution Approach

1. Maintain a frequency count of characters.
2. For each index `i`, add `i - freq[s[i]]` to the result. This counts swaps with different characters before it.
3. If any character has frequency > 1, include the original string once in the result.

### Tags

* String
* Hashing
* Greedy
* Combinatorics
