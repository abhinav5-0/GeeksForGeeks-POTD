# K Sized Subarray Maximum

## Problem Statement

Given an array `arr[]` of positive integers and an integer `k`, find the **maximum element** in every **contiguous subarray of size k**.

---

## Example

**Input**

```
arr = [1, 2, 3, 1, 4, 5, 2, 3, 6]
k = 3
```

**Output**

```
[3, 3, 4, 5, 5, 5, 6]
```

---

## Approach (Sliding Window + Deque)

Because the array size can be very large (up to `10^6`), a brute-force solution will not work.

We use a **Deque (Double Ended Queue)** to efficiently keep track of maximum elements in each window.

### Key Ideas

* The deque stores **indices**, not values
* Elements in the deque are always in **decreasing order** of values
* The **front** of the deque always contains the index of the maximum element of the current window

---

## Step-by-Step Algorithm

1. Remove indices that are **outside the current window**
2. Remove elements from the back of the deque that are **smaller than the current element**
3. Add the current index to the deque
4. When the window size becomes `k`, record the maximum (front of deque)

---

## C++ Code

```cpp
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq;

        for (int i = 0; i < arr.size(); i++) {
            // Remove elements out of window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Store maximum of window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        return result;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(k)`

---

## Special Case

If `k = 1`, every element is its own window, so the output is the same as the input array.

---

## Summary

This is a classic **Sliding Window + Deque** problem.

Using a deque helps us avoid unnecessary comparisons and gives an optimal solution even for large inputs.

Happy Coding 🚀
