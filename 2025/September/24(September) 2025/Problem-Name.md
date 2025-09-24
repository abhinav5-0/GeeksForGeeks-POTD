# Design MinMax Queue

## Problem Statement
Design a **SpecialQueue** data structure that functions like a normal queue but with additional support for retrieving the minimum and maximum element efficiently.

The SpecialQueue must support the following operations:
- **enqueue(x):** Insert an element `x` at the rear of the queue.
- **dequeue():** Remove the element from the front of the queue.
- **getFront():** Return the front element without removing.
- **getMin():** Return the minimum element in the queue in **O(1)** time.
- **getMax():** Return the maximum element in the queue in **O(1)** time.

Queries are given in numeric form:
- `1 x` : Call `enqueue(x)`
- `2` : Call `dequeue()`
- `3` : Call `getFront()`
- `4` : Call `getMin()`
- `5` : Call `getMax()`

It is guaranteed that all queries are valid.

---

## Example 1
**Input:**
```
q = 6
queries = [[1, 4], [1, 2], [3], [4], [2], [5]]
```

**Output:**
```
[4, 2, 2]
```

**Explanation:**
- enqueue(4) → queue = [4]
- enqueue(2) → queue = [4, 2]
- getFront() → 4
- getMin() → 2
- dequeue() → queue = [2]
- getMax() → 2

---

## Example 2
**Input:**
```
q = 4
queries = [[1, 3], [4], [1, 5], [5]]
```

**Output:**
```
[3, 5]
```

**Explanation:**
- enqueue(3) → queue = [3]
- getMin() → 3
- enqueue(5) → queue = [3, 5]
- getMax() → 5

---

## Constraints
- 1 ≤ queries.size() ≤ 10^5
- 0 ≤ values in the queue ≤ 10^9

---

## Approach
We maintain:
- A normal queue for storing elements in FIFO order.
- A **minDeque** to keep track of the minimum element.
- A **maxDeque** to keep track of the maximum element.

Both deques are updated on each enqueue and dequeue to maintain O(1) access to min and max values.

---

## Implementation (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
    queue<int> q;
    deque<int> minDeque, maxDeque; // For tracking min and max

public:
    // Insert element into the queue
    void enqueue(int x) {
        q.push(x);

        // Maintain minDeque (increasing order)
        while (!minDeque.empty() && minDeque.back() > x)
            minDeque.pop_back();
        minDeque.push_back(x);

        // Maintain maxDeque (decreasing order)
        while (!maxDeque.empty() && maxDeque.back() < x)
            maxDeque.pop_back();
        maxDeque.push_back(x);
    }

    // Remove element from the queue
    void dequeue() {
        if (q.empty()) return;

        int front = q.front();
        q.pop();

        // Sync with minDeque
        if (!minDeque.empty() && minDeque.front() == front)
            minDeque.pop_front();

        // Sync with maxDeque
        if (!maxDeque.empty() && maxDeque.front() == front)
            maxDeque.pop_front();
    }

    // Get front element
    int getFront() {
        return q.front();
    }

    // Get minimum element
    int getMin() {
        return minDeque.front();
    }

    // Get maximum element
    int getMax() {
        return maxDeque.front();
    }
};
