# Last Moment Before All Ants Fall Out

**Difficulty:** Medium
**Accuracy:** 65.63%
**Submissions:** 10K+
**Points:** 4

---

## Problem Statement

We have a wooden plank of length `n` units. Some ants are walking on the plank, each moving with a speed of **1 unit per second**.

* Some ants move **left**, and some move **right**.
* When two ants moving in opposite directions meet, they **change directions and continue moving**.
* The direction change is **instantaneous** and has **no time cost**.
* When an ant reaches either end of the plank, it **falls off immediately**.

Given:

* An integer `n` (length of the plank)
* Two integer arrays `left[]` and `right[]` representing the positions of ants moving **left** and **right**

Return the **time when the last ant(s) fall out** of the plank.

---

## Examples

### Example 1:

**Input:**

```
n = 4
left = [2]
right = [0, 1, 3]
```

**Output:**

```
4
```

**Explanation:**

* The ant at position 2 takes 2 seconds to fall left.
* The ant at position 0 takes 4 seconds to fall right.
* The last ant falls off at time 4.

---

### Example 2:

**Input:**

```
n = 4
left = []
right = [0, 1, 2, 3, 4]
```

**Output:**

```
4
```

**Explanation:**

* All ants go to the right. The one at position 0 takes 4 seconds to fall.

---

### Example 3:

**Input:**

```
n = 3
left = [0]
right = [3]
```

**Output:**

```
0
```

**Explanation:**

* The ants are already at the edges and fall immediately.

---

## Constraints

* `1 <= n <= 10^5`
* `0 <= left.length, right.length <= n + 1`
* `0 <= left[i], right[i] <= n`
* `1 <= left.length + right.length <= n + 1`
* All values in `left` and `right` are **unique** and **do not overlap**

---

## Optimal Approach

Since ants **swap directions** when they meet, but this doesn’t affect their **final fall-off time**, we can ignore the interaction.

* For ants moving **left**, fall time = `position`
* For ants moving **right**, fall time = `n - position`

We need the **maximum of all these values**.

---

## Optimized C++ Code

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int maxRight = right.empty() ? 0 : n - *min_element(right.begin(), right.end());
        return max(maxLeft, maxRight);
    }
};
```

---

## Tags

`Simulation`, `Greedy`, `Math`, `Two Pointers`
