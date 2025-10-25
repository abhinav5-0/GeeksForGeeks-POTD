## Minimum Steps to Halve Sum

**Difficulty:** Medium
**Accuracy:** 60.23%
**Submissions:** 9K+
**Points:** 4

### Problem Statement

Given an array `arr[]`, find the minimum number of operations required to make the sum of its elements less than or equal to half of the original sum. In one operation, you may replace any element with half of its value (with floating-point precision).

### Examples

**Input:** `arr[] = [8, 6, 2]`
**Output:** `3`
**Explanation:**
Initial sum = (8 + 6 + 2) = 16, half = 8

* Halve 8 → arr[] = [4, 6, 2], sum = 12 (still > 8)
* Halve 6 → arr[] = [4, 3, 2], sum = 9 (still > 8)
* Halve 2 → arr[] = [4, 3, 1], sum = 8  ✅

**Input:** `arr[] = [9, 1, 2]`
**Output:** `2`
**Explanation:**
Initial sum = 12, half = 6

* Halve 9 → arr[] = [4.5, 1, 2], sum = 7.5 (still > 6)
* Halve 4.5 → arr[] = [2.25, 1, 2], sum = 5.25 ≤ 6  ✅

### Constraints

* 1 ≤ arr.size() ≤ 10^5
* 0 ≤ arr[i] ≤ 10^4

---

### Approach

1. Compute the **initial sum** of the array.
2. The **target** is to make the sum ≤ half of its original value.
3. Use a **max heap (priority queue)** to always pick and halve the **largest element**.
4. Keep track of the **reduction** from the total sum.
5. Stop when the reduction is at least half the original sum.

#### Intuition

Each halving operation gives the **maximum reduction** when applied to the largest element. Hence, we use a **priority queue** to always pick the current maximum efficiently.

---

### Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq; // max heap for floating values
        double totalSum = 0;
        
        for (int x : arr) {
            pq.push(x);
            totalSum += x;
        }
        
        double target = totalSum / 2.0;
        double reduced = 0;
        int operations = 0;
        
        while (reduced < target) {
            double largest = pq.top(); pq.pop();
            double half = largest / 2.0;
            
            reduced += half;       // reduction amount
            pq.push(half);         // push halved value back
            operations++;
        }
        
        return operations;
    }
};
```

---

### Example Walkthrough

**Input:** `arr = [8, 6, 2]`
**Initial sum:** 16 → target = 8

| Step | Heap Top | Halve | Reduced So Far | Operations |
| ---- | -------- | ----- | -------------- | ---------- |
| 1    | 8        | 4     | 4              | 1          |
| 2    | 6        | 3     | 7              | 2          |
| 3    | 4        | 2     | 9              | 3          |

✅ Reduced (9) ≥ Target (8) → Done
**Output = 3**

---

### Complexity Analysis

* **Time Complexity:** O(n log n + k log n), where k is the number of halving operations.
* **Space Complexity:** O(n) for the priority queue.

---

### Key Idea

Always halve the largest number available to minimize the total number of operations needed to reduce the array sum to half or less.
