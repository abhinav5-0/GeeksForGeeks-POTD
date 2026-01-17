# Expression Contains Redundant Brackets

## Problem Statement

You are given a **balanced mathematical expression** as a string `s` containing:

* lowercase letters (operands)
* operators: `+ , - , * , /`
* parentheses `(` and `)`

Your task is to check whether the expression contains **redundant (unnecessary) brackets**.

A set of brackets is considered **redundant** if:

* They do not enclose any operator, or
* The same sub-expression is surrounded by extra parentheses

Return **true** if redundant brackets are present, otherwise return **false**.

---

## Examples

### Example 1

**Input:** `((a+b))`
**Output:** `true`
**Reason:** Extra parentheses around `(a+b)` are unnecessary.

### Example 2

**Input:** `(a+(b)/c)`
**Output:** `true`
**Reason:** `(b)` does not change the expression → redundant.

### Example 3

**Input:** `(a+b+(c+d))`
**Output:** `false`
**Reason:** All parentheses are required.

---

## Key Idea (Stack Based Approach)

We use a **stack** to process the expression character by character.

### Observation

* A pair of parentheses is **useful** only if it contains **at least one operator** inside.
* If we find `()` or `(a)` without any operator inside → **redundant**.

---

## Algorithm Steps

1. Create an empty stack of characters.
2. Traverse the string `s` from left to right.
3. For every character:

   * If it's **not a closing bracket `)`**, push it onto the stack.
   * If it **is `)`**:

     * Pop elements until `'('` is found.
     * Check whether an operator (`+ - * /`) was present in between.
     * If **no operator found**, return `true` (redundant).
     * Pop the `'('`.
4. If traversal finishes without finding redundancy → return `false`.

---

## Why This Works

* Parentheses without operators do not affect evaluation.
* Stack helps us inspect exactly what lies inside each pair of brackets.
* Time Complexity: **O(n)**
* Space Complexity: **O(n)**

---

## Conclusion

This stack-based method efficiently detects unnecessary parentheses even for large expressions (up to `10^5` length).

✔ Fast
✔ Simple logic
✔ Interview-friendly approach

---

*(Code implementation can be written easily in C++, Java, or Python using this logic.)*
