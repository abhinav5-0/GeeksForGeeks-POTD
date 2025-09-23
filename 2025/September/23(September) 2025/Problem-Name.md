# Queue Reversal

**Difficulty:** Easy
**Accuracy:** 77.98%
**Submissions:** 150K+
**Points:** 2

---

## Problem Statement

Given a queue `q` containing integer elements, your task is to reverse the queue.

### Examples

**Input:**

```
q[] = [5, 10, 15, 20, 25]
```

**Output:**

```
[25, 20, 15, 10, 5]
```

**Explanation:** After reversing, the resultant queue will be 25 20 15 10 5.

---

**Input:**

```
q[] = [1, 2, 3, 4, 5]
```

**Output:**

```
[5, 4, 3, 2, 1]
```

**Explanation:** After reversing, the resultant queue will be 5 4 3 2 1.

---

### Constraints

* 1 ≤ q.size() ≤ 10^3
* 0 ≤ q\[i] ≤ 10^5

---

## Solutions

### 1. Using Stack (Iterative)

We can use a stack to reverse the queue.

```cpp
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        
        // Step 1: Push all elements into stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        
        // Step 2: Pop from stack and push back into queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

### 2. Using Recursion

We can also reverse the queue without an explicit stack.

```cpp
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if (q.empty()) return;
        
        int front = q.front();
        q.pop();
        
        reverseQueue(q);   // reverse remaining queue
        
        q.push(front);     // insert element at the back
    }
};
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) (due to recursion stack)

---

## Dry Run (Recursive Approach)

For `q = [1, 2, 3]`:

1. Remove `1`, call recursion with `[2, 3]`
2. Remove `2`, call recursion with `[3]`
3. Remove `3`, recursion hits base case (empty)
4. Push back `3` → `[3]`
5. Push back `2` → `[3, 2]`
6. Push back `1` → `[3, 2, 1]`

✅ Final reversed queue: `[3, 2, 1]`
