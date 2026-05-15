# Special Keyboard

**Difficulty:** Medium  
**Accuracy:** 28.66%  
**Submissions:** 60K+  
**Points:** 4  

---

## Problem Statement

Given a special keyboard that contains only four keys:

1. **Key 1:** Prints a single character `'A'` on the screen.
2. **Key 2 (Ctrl + A):** Selects all the characters currently present on the screen.
3. **Key 3 (Ctrl + C):** Copies the selected characters to a buffer.
4. **Key 4 (Ctrl + V):** Pastes the content of the buffer onto the screen, appending it to the existing text.

Initially, the screen is empty and the buffer is also empty.

Determine the **maximum number of `'A'`** characters that can be displayed on the screen after performing **exactly `n` key presses**.

---

# Examples

## Example 1

### Input
```txt
n = 3
