# Longest Periodic Proper Prefix

**Difficulty:** Hard
**Accuracy:** 49.98%
**Points:** 8

## Problem Statement

Given a string `s`, find the length of the **longest periodic proper prefix** of `s`. If no such prefix exists, return `-1`.

A **periodic proper prefix** is a non-empty prefix of `s` (but not the whole string), such that repeating this prefix enough times produces a string that starts with `s`.

### Examples

**Input:**

```
s = "aaaaaa"
```

**Output:**

```
5
```

**Explanation:**
Repeating the proper prefix `"aaaaa"` forms `"aaaaaaaaaa..."`, which starts with `"aaaaaa"`. No longer proper prefix satisfies this.

**Input:**

```
s = "abcab"
```

**Output:**

```
3
```

**Explanation:**
Repeating the proper prefix `"abc"` forms `"abcabc..."`, which starts with `"abcab"`.

**Input:**

```
s = "ababd"
```

**Output:**

```
-1
```

**Explanation:**
No proper prefix satisfies the condition.

---

## Constraints

* `1 ≤ s.size() ≤ 10^5`
* `s` consists of lowercase English alphabets

---

## Approach

This problem can be efficiently solved using the **Z-algorithm**.

### Why Z-algorithm?

The Z-array for a string `s` is defined as:

```
Z[i] = length of the longest substring starting at i that is also a prefix of s.
```

If for some index `i`, `Z[i] == n - i` (where `n` is the string length), it means that the substring starting at `i` is identical to the prefix of length `n-i`. This directly indicates a periodic proper prefix of length `n-i`.

We can iterate through the Z-array and find the maximum such length.

### Algorithm Steps

1. Compute the Z-array for the given string.
2. Iterate over `i` from `1` to `n-1`:

   * If `Z[i] == n - i`, store `i` as the starting point of a matching suffix.
3. The answer is `n - ans` if `ans != -1`, otherwise `-1`.

---

## Code Implementation (C++)

```cpp
class Solution {
public:
    int getLongestPrefix(string s) {
        int n = s.size(), l = 0, r = 0, ans = -1;
        vector<int> z(n);
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            if (z[i] == n - i) ans = i; // Found a periodic prefix
        }
        return (ans == -1 ? -1 : n - ans);
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)` — Z-algorithm runs in linear time.
* **Space Complexity:** `O(n)` — to store the Z-array.

---

## Dry Run Example

For `s = "abcab"`:

* `Z = [0, 0, 0, 2, 0]`
* At `i=2`: no match
* At `i=3`: `z[3] = 2`, `n-i = 2` → match found
* Result: `n - i = 3` → prefix length = 3
