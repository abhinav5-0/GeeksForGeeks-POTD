# String Stack Problem

## Problem Statement
You are given two strings `pat` and `tar` consisting of lowercase English characters. You can construct a new string `s` by performing any one of the following operations for each character in `pat`:

1. Append the character `pat[i]` to the string `s`.
2. Delete the last character of `s` (if `s` is empty do nothing).

After performing operations on every character of `pat` exactly once, your goal is to determine if it is possible to make the string `s` equal to string `tar`.

### Examples

**Input:**
```
pat = "geuaek", tar = "geek"
```
**Output:**
```
true
```
**Explanation:**
- Append 'g', 'e', 'u' → s = "geu"  
- Delete last for 'a' → s = "ge"  
- Append 'e', 'k' → s = "geek"  
- Matches `tar` ✅

---

**Input:**
```
pat = "agiffghd", tar = "gfg"
```
**Output:**
```
true
```
**Explanation:**
- Skip 'a'  
- Append 'g', 'i' → s = "gi"  
- Delete 'f' → s = "g"  
- Append 'f', 'g', 'h' → s = "gfgh"  
- Delete 'd' → s = "gfg"  
- Matches `tar` ✅

---

**Input:**
```
pat = "ufahs", tar = "aus"
```
**Output:**
```
false
```
**Explanation:**
Impossible to construct `tar` with the given operations ❌

---

## Constraints
- 1 ≤ pat.size(), tar.size() ≤ 10^5

---

## Approach
Instead of simulating with a stack, we can solve it efficiently using **two pointers**:

1. Start from the end of both strings (`pat` and `tar`).
2. If characters match, move both pointers.
3. If they don’t match, skip the `pat` character (as it could have been pushed & popped).
4. If we consume all characters of `tar`, it’s possible.

---

## C++ Solution
```cpp
class Solution {
public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.size() - 1;
        int j = tar.size() - 1;

        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                // Match found, move both
                i--;
                j--;
            } else {
                // Skip pat character (pushed then popped)
                i--;
            }
        }

        // If we consumed all of tar, it's possible
        return (j < 0);
    }
};
```

---

## Complexity
- **Time Complexity:** O(n), where n = `pat.size()`
- **Space Complexity:** O(1)

---

## Dry Run Example
**pat = "geuaek"**, **tar = "geek"**

- i=5 (k), j=3 (k) → match → i=4, j=2
- i=4 (e), j=2 (e) → match → i=3, j=1
- i=3 (a), j=1 (e) → skip → i=2
- i=2 (u), j=1 (e) → skip → i=1
- i=1 (e), j=1 (e) → match → i=0, j=0
- i=0 (g), j=0 (g) → match → i=-1, j=-1

All of `tar` consumed → ✅ Possible.
