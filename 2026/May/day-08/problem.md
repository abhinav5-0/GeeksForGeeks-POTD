# Remove Invalid Parentheses

**Difficulty:** Hard
**Accuracy:** 43.53%
**Submissions:** 18K+
**Points:** 8
**Average Time:** 40m

---

## Problem Statement

Given a string `s` consisting of lowercase letters and parentheses `'('` and `')'`.

A string is considered **valid** if:

* Every opening parenthesis `'('` has a corresponding closing parenthesis `')'`.
* Parentheses are properly nested.

Remove the **minimum** number of invalid parentheses from `s` so that the resulting string becomes valid.

Return all the possible **distinct** valid strings in **lexicographically sorted order**.

---

# Examples

## Example 1

### Input

```txt
s = "()())()"
```

### Output

```txt
["(())()", "()()()"]
```

### Explanation

The string `"()())()"` has one extra `')'`, making it invalid.
By removing one `')'`, we can make it valid in two ways:

* Remove the 3rd index `')'` → `"(())()"`
* Remove the 4th index `')'` → `"()()()"`

Both are valid and require the minimum removals.

---

## Example 2

### Input

```txt
s = "(a)())()"
```

### Output

```txt
["(a())()", "(a)()()"]
```

### Explanation

We remove one `')'` (minimum removals) to make it valid.
Possible valid results:

* Remove a `')'` → `"(a())()"`
* Remove another `')'` → `"(a)()()"`

---

## Example 3

### Input

```txt
s = ")("
```

### Output

```txt
[""]
```

### Explanation

The string `")("` is invalid.
Removing both parentheses (minimum removals) gives an empty string `""`, which is valid.

---

# Constraints

```txt
1 ≤ |s| ≤ 20
```

* `s` consists of lowercase English letters and parentheses `'('` and `')'`.

---

# Function Signature

```cpp
class Solution {
public:
    vector<string> validParenthesis(string &s) {
        // code here
    }
};
```

---

# Notes

* Return only **distinct** valid strings.
* Output must be in **lexicographical order**.
* Minimum removals are required.
* Lowercase letters should remain unchanged.
