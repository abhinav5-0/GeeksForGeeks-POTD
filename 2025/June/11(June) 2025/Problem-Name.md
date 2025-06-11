# Problem: Remove the Balls

**Difficulty:** Medium
**Accuracy:** 58.66%
**Submissions:** 35K+
**Points:** 4

---

## Problem Statement

You are given two arrays, `color` and `radius`, representing a sequence of balls:

* `color[i]` is the color of the i-th ball.
* `radius[i]` is the radius of the i-th ball.

If two **consecutive** balls have the **same color** and **same radius**, remove them both. Repeat this process until no more such pairs exist.

Return the **number of balls remaining** after all possible removals.

---

## Examples

### Example 1:

**Input:**
`color[] = [2, 3, 5]`
`radius[] = [3, 3, 5]`

**Output:**
`3`

**Explanation:**
All the 3 balls have different colors and radius, so none can be removed.

---

### Example 2:

**Input:**
`color[] = [2, 2, 5]`
`radius[] = [3, 3, 5]`

**Output:**
`1`

**Explanation:**
The first and second balls have the same color (2) and radius (3). After removing them, only one ball is left which cannot be removed.

---

## Constraints

* `1 <= color.size() = radius.size() <= 10^5`
* `1 <= color[i] <= 10^9`
* `1 <= radius[i] <= 10^9`

---

## Solution Outline

Use a **stack** to track the current state of the sequence. Iterate through the arrays, and for each ball:

* If the top of the stack has the same color and radius, remove (pop) it.
* Otherwise, push the current ball onto the stack.

At the end, the size of the stack will be the number of remaining balls.

---

## C++ Function Signature

```cpp
class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius);
};
```
