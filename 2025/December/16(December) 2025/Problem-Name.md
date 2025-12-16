# Strings Rotations of Each Other

## Problem Statement

You are given two strings **s1** and **s2** of equal length. Your task is to check whether **s2** is a rotation of **s1**.

A string is said to be a rotation of another if it can be obtained by moving characters from the start to the end (left rotation) or from the end to the start (right rotation), without changing the order of characters.

---

## Examples

### Example 1

**Input:**

```
s1 = "abcd"
s2 = "cdab"
```

**Output:**

```
true
```

**Explanation:** After 2 right rotations, `s1` becomes `cdab`.

---

### Example 2

**Input:**

```
s1 = "aab"
s2 = "aba"
```

**Output:**

```
true
```

**Explanation:** After 1 left rotation, `s1` becomes `aba`.

---

### Example 3

**Input:**

```
s1 = "abcd"
s2 = "acbd"
```

**Output:**

```
false
```

**Explanation:** Strings are not rotations of each other.

---

## Key Idea

If **s2** is a rotation of **s1**, then **s2** must be a substring of **(s1 + s1)**.

### Why does this work?

All possible rotations of `s1` will always appear as substrings inside `s1 + s1`.

---

## Algorithm

1. If the lengths of `s1` and `s2` are different, return `false`.
2. Concatenate `s1` with itself.
3. Check if `s2` is a substring of the concatenated string.

---

## C++ Implementation

```cpp
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return false;

        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)

Where `n` is the length of the string.

---

## Conclusion

This approach is efficient, clean, and widely accepted in coding interviews and competitive programming platforms. It correctly handles both left and right rotations in linear time.
