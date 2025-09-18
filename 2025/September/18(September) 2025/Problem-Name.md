# Next Greater Element in Circular Array

## Problem Statement
Given a circular integer array `arr[]`, the task is to determine the next greater element (NGE) for each element in the array.

- The **next greater element** of an element `arr[i]` is the first element that is greater than `arr[i]` when traversing circularly.
- If no such element exists, return `-1` for that position.
- Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

### Examples

**Input:**
```text
arr = [1, 3, 2, 4]
```
**Output:**
```text
[3, 4, 4, -1]
```
**Explanation:**
- NGE of 1 is 3
- NGE of 3 is 4
- NGE of 2 is 4
- NGE of 4 is -1

**Input:**
```text
arr = [0, 2, 3, 1, 1]
```
**Output:**
```text
[2, 3, -1, 2, 2]
```
**Explanation:**
- NGE of 0 is 2
- NGE of 2 is 3
- NGE of 3 is -1
- NGE of 1 is 2
- NGE of 1 is 2

### Constraints
- 1 ≤ arr.size() ≤ 10^5
- 0 ≤ arr[i] ≤ 10^6

---

## Approach
We use a **monotonic stack** and traverse the array twice to simulate the circular behavior.

### Steps
1. Create a result array `res` initialized with `-1`.
2. Use a stack to store **indices** of elements whose NGE is not yet found.
3. Traverse the array from `2*n - 1` down to `0`:
   - Use `i % n` to handle circular indexing.
   - While stack is not empty and `arr[stack.top()] <= arr[idx]`, pop from stack.
   - If stack not empty, set `res[idx] = arr[stack.top()]`.
   - Push current index to stack.
4. Return result.

---

## C++ Implementation
```cpp
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st; // will store indices

        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Maintain decreasing stack
            while (!st.empty() && arr[st.top()] <= arr[idx]) {
                st.pop();
            }

            // If stack not empty, the top is next greater
            if (!st.empty()) {
                res[idx] = arr[st.top()];
            }

            st.push(idx);
        }

        return res;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** O(n) — each element is pushed and popped at most once.
- **Space Complexity:** O(n) — for the stack and result array.

---

## Example Walkthrough
**Input:**
```text
arr = [1, 3, 2, 4]
```
**Execution:**
- NGE(1) = 3
- NGE(3) = 4
- NGE(2) = 4
- NGE(4) = -1

**Output:**
```text
[3, 4, 4, -1]
