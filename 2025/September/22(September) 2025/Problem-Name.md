# Max of Min for Every Window Size

**Difficulty:** Hard
**Accuracy:** 42.9%
**Submissions:** 75K+
**Points:** 8
**Average Time:** 45m

---

## Problem Statement

You are given an integer array `arr[]`. The task is to find the maximum of minimum values for every window size `k` where `1 ≤ k ≤ arr.size()`.

For each window size `k`, consider all contiguous subarrays of length `k`, determine the minimum element in each subarray, and then take the maximum among all these minimums.

Return the results as an array, where the element at index `i` represents the answer for window size `i+1`.

---

## Examples

### Example 1:

**Input:**

```
arr = [10, 20, 30, 50, 10, 70, 30]
```

**Output:**

```
[70, 30, 20, 10, 10, 10, 10]
```

**Explanation:**

* Window size 1 → minimums = \[10, 20, 30, 50, 10, 70, 30], maximum = 70
* Window size 2 → minimums = \[10, 20, 30, 10, 10, 30], maximum = 30
* Window size 3 → minimums = \[10, 20, 10, 10, 10], maximum = 20
* Window sizes 4–7 → minimums = \[10, 10, 10, 10], maximum = 10

### Example 2:

**Input:**

```
arr = [10, 20, 30]
```

**Output:**

```
[30, 20, 10]
```

**Explanation:**

* Window size 1 → maximum of minimums = 30
* Window size 2 → maximum of minimums = 20
* Window size 3 → maximum of minimums = 10

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^6`

---

## Approach

This is a **monotonic stack + contribution** problem.

1. For each element `arr[i]`, determine the **Previous Smaller Element (PSE)** and **Next Smaller Element (NSE)**.

   * `left[i]` → index of the previous smaller element.
   * `right[i]` → index of the next smaller element.

2. Using these, calculate the **maximum window size** where `arr[i]` is the minimum:

   ```
   len = right[i] - left[i] - 1
   ```

3. Update `res[len]` with the maximum possible value:

   ```
   res[len] = max(res[len], arr[i])
   ```

4. After filling, propagate values backward:

   ```
   for k = n-1 down to 1:
       res[k] = max(res[k], res[k+1])
   ```

5. Return the result array.

---

## C++ Solution

```cpp
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        vector<int> res(n + 1, 0);

        // Fill values
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            res[len] = max(res[len], arr[i]);
        }

        // Propagate maximums
        for (int i = n - 1; i >= 1; i--) {
            res[i] = max(res[i], res[i + 1]);
        }

        res.erase(res.begin()); // drop index 0
        return res;
    }
};
```

---

## Time Complexity

* Finding PSE + NSE: **O(n)**
* Filling result array: **O(n)**
* Backward propagation: **O(n)**

**Overall:** `O(n)`

## Space Complexity

* Auxiliary arrays + stack: **O(n)**

---
