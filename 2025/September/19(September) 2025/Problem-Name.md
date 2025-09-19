# Min Add to Make Parentheses Valid

**Difficulty:** Medium
**Accuracy:** 61.08%
**Submissions:** 10K+
**Points:** 4

---

## Problem Statement

You are given a string `s` consisting only of the characters `'('` and `')'`. Your task is to determine the minimum number of parentheses (either `'('` or `')'`) that must be inserted at any positions to make the string `s` a valid parentheses string.

A parentheses string is considered valid if:

* Every opening parenthesis `'('` has a corresponding closing parenthesis `')'`.
* Every closing parenthesis `')'` has a corresponding opening parenthesis `'('`.
* Parentheses are properly nested.

---

## Examples

**Input:** `s = "(()("`
**Output:** `2`
**Explanation:** There are two unmatched `'('` at the end, so we need to add two `')'`.

**Input:** `s = "))))"`
**Output:** `4`
**Explanation:** Four `'('` need to be added at the start to make the string valid.

**Input:** `s = ")()()"`
**Output:** `1`
**Explanation:** The very first `')'` is unmatched, so we need to add one `'('` at the beginning.

---

## Constraints

* `1 ≤ s.size() ≤ 10^5`
* `s[i] ∈ { '(', ')' }`

---

## Approach

We can solve this problem using counters instead of a stack:

1. Use a variable `open` to count unmatched `'('`.
2. Use a variable `add` to count unmatched `')'`.
3. Traverse the string:

   * If the character is `'('`, increment `open`.
   * If the character is `')'`:

     * If `open > 0`, decrement `open` (this `')'` matches an earlier `'('`).
     * Otherwise, increment `add` (this `')'` is unmatched and needs a `'('`).
4. The final answer will be `open + add`.

   * `open` counts unmatched `'('` that need `')'`.
   * `add` counts unmatched `')'` that need `'('`.

---

## C++ Implementation

```cpp
class Solution {
public:
    int minParentheses(string& s) {
        int open = 0;  // count of unmatched '('
        int add = 0;   // count of unmatched ')'

        for (char c : s) {
            if (c == '(') {
                open++;
            } else { // c == ')'
                if (open > 0) {
                    open--; // match with a '('
                } else {
                    add++; // need to insert '('
                }
            }
        }

        return add + open;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)` — single traversal of the string.
* **Space Complexity:** `O(1)` — only a few counters used.

---

## Key Takeaway

This problem demonstrates that you don’t always need a stack for parenthesis problems — simple counters for unmatched parentheses are enough to track balance and compute the minimum insertions.
