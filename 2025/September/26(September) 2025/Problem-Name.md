# Rotate Deque By K

**Difficulty:** Easy
**Accuracy:** 75.79%
**Submissions:** 20K+
**Points:** 2

---

## Problem Statement

You are given a deque `dq` (double-ended queue) containing non-negative integers, along with two positive integers `type` and `k`. The task is to rotate the deque circularly by `k` positions.

There are two types of rotation operations:

1. **Right Rotation (Clockwise)**: If `type = 1`, rotate the deque to the right. This means moving the last element to the front, and repeating the process `k` times.
2. **Left Rotation (Anti-Clockwise)**: If `type = 2`, rotate the deque to the left. This means moving the first element to the back, and repeating the process `k` times.

---

## Examples

**Example 1:**

```
Input: dq = [1, 2, 3, 4, 5, 6], type = 1, k = 2
Output: [5, 6, 1, 2, 3, 4]

Explanation:
- First right rotation → [6, 1, 2, 3, 4, 5]
- Second right rotation → [5, 6, 1, 2, 3, 4]
```

**Example 2:**

```
Input: dq = [10, 20, 30, 40, 50], type = 2, k = 3
Output: [40, 50, 10, 20, 30]

Explanation:
- First left rotation → [20, 30, 40, 50, 10]
- Second left rotation → [30, 40, 50, 10, 20]
- Third left rotation → [40, 50, 10, 20, 30]
```

---

## Constraints

* 1 ≤ dq.size() ≤ 10^5
* 1 ≤ k ≤ 10^5
* 1 ≤ type ≤ 2

---

## Approach

1. Since rotating `n` times (where `n = dq.size()`) brings the deque back to its original state, we only need to perform `k % n` rotations.
2. For **type = 1 (Right rotation)**: move last `k` elements to the front.
3. For **type = 2 (Left rotation)**: move first `k` elements to the back.
4. Use **`std::rotate`** for efficient `O(n)` rearrangement instead of performing `k` individual operations.

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;
        k %= n; // optimize rotations

        if (type == 1) {
            // Right rotation
            rotate(dq.begin(), dq.end() - k, dq.end());
        } else if (type == 2) {
            // Left rotation
            rotate(dq.begin(), dq.begin() + k, dq.end());
        }
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(n), since `std::rotate` performs shifting in linear time.
* **Space Complexity:** O(1), in-place rearrangement.

---

## Key Notes

* Use modulo to avoid unnecessary full rotations.
* `std::rotate` makes the solution clean and efficient.
* Works for both large `n` and `k` within constraints.
