# Stock Span Problem

## Problem Statement

The **stock span problem** is a classic stack-based problem.

You are given an array `arr[]` where `arr[i]` represents the stock price on the *i-th day*.

The **span** of a stock on day `i` is defined as the number of consecutive days **ending at day i** for which the stock price was **less than or equal to** the price on day `i`.

You need to return an array where each element represents the span for that day.

---

## Example 1

**Input**:

```
arr = [100, 80, 90, 120]
```

**Output**:

```
[1, 1, 2, 4]
```

### Explanation

* Day 0 (100): No previous days → span = 1
* Day 1 (80): Smaller than 100 → span = 1
* Day 2 (90): Greater than 80 → span = 2
* Day 3 (120): Greater than all previous → span = 4

---

## Example 2

**Input**:

```
arr = [10, 4, 5, 90, 120, 80]
```

**Output**:

```
[1, 1, 2, 4, 5, 1]
```

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^5`

---

## Optimal Approach (Using Stack)

### Key Idea

* Use a **monotonic decreasing stack** that stores indices of days.
* For each day `i`, pop all previous days from the stack whose price is **≤ current price**.
* If stack becomes empty → span = `i + 1`
* Else → span = `i - stack.top()`

This ensures **O(n)** time complexity.

---

## Algorithm Steps

1. Create an empty stack to store indices
2. Initialize a span array
3. Traverse the array from left to right
4. While stack is not empty and `arr[stack.top()] ≤ arr[i]`, pop
5. Compute span
6. Push current index to stack

---

## C++ Implementation

```cpp
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            span[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return span;
    }
};
```

---

## Time and Space Complexity

* **Time Complexity**: `O(n)`
* **Space Complexity**: `O(n)` (stack + span array)

---

## Important Notes

* This problem is similar to **Previous Greater Element**
* Stack helps avoid unnecessary comparisons
* Very frequently asked in interviews

---

### ✅ Tip

If you understand this problem well, you can easily solve:

* Next Greater Element
* Histogram Area
* Daily Temperatures

---

Happy Coding 🚀
