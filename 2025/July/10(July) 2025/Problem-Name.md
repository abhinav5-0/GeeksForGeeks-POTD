# Problem: Find the Longest String

**Difficulty:** Medium
**Accuracy:** 56.04%
**Submissions:** 32K+
**Points:** 4

---

## Problem Statement

Given an array of strings `words[]`, find the longest string in `words[]` such that every prefix of it is also present in the array `words[]`.

If multiple strings have the same maximum length, return the **lexicographically smallest** one.

---

## Examples

### Example 1:

**Input:**
`words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]`

**Output:**
`pros`

**Explanation:**
"pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present in the array `words[]`.

---

### Example 2:

**Input:**
`words[] = ["ab", "a", "abc", "abd"]`

**Output:**
`abc`

**Explanation:**
Both "abc" and "abd" have all prefixes in the array. Since "abc" is lexicographically smaller than "abd", the output is "abc".

---

## Constraints

* `1 ≤ words.length ≤ 10^3`
* `1 ≤ words[i].length ≤ 10^3`

---

## Function Signature

```cpp
class Solution {
  public:
    string longestString(vector<string> &words);
};
```

---

## Expected Time Complexity

* **Efficient Solution:** O(N \* L) for inserting and traversing the Trie, where N is the number of words and L is the average length of the words.

---

## Tags

`Trie` `Strings` `Prefix Matching` `Lexicographical Order`
