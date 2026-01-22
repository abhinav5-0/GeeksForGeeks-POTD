# Sum of Subarray Ranges

## Problem Recap

For every possible subarray, define its **range** as:

> **range = (maximum element) − (minimum element)**

Your task is to compute the **sum of ranges of all subarrays**.

Brute force checking all subarrays is **O(n²)**, which is impossible for `n` up to `10⁶`.

---

## Key Insight 💡

Instead of calculating max–min for every subarray:

👉 **Count how many subarrays each element contributes as:**

* **maximum**
* **minimum**

Then:

```
Answer = (Sum of contributions as maximum) − (Sum of contributions as minimum)
```

This reduces the problem to **monotonic stack** usage.

---

## Contribution Logic

For an element `arr[i]`:

### As Maximum

* Find the **previous greater element** (PGE)
* Find the **next greater element** (NGE)

Number of subarrays where `arr[i]` is maximum:

```
left = i − PGE
right = NGE − i
count = left × right
contribution = arr[i] × count
```

### As Minimum

* Find the **previous smaller element** (PSE)
* Find the **next smaller element** (NSE)

Same formula applies.

---

## Why Monotonic Stack?

Stacks help find **previous/next greater or smaller** in **O(n)** time.

Total complexity becomes:

* **Time:** O(n)
* **Space:** O(n)

---

## C++ Implementation

```cpp
class Solution {
public:
    int subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n), nge(n), pse(n), nse(n);
        stack<int> st;

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long maxSum = 0, minSum = 0;

        for (int i = 0; i < n; i++) {
            long long maxCount = (long long)(i - pge[i]) * (nge[i] - i);
            long long minCount = (long long)(i - pse[i]) * (nse[i] - i);
            maxSum += arr[i] * maxCount;
            minSum += arr[i] * minCount;
        }

        return (int)(maxSum - minSum);
    }
};
```

---

## Example Walkthrough

### Input

```
[1, 2, 3]
```

* Max contributions = `1×1 + 2×2 + 3×3`
* Min contributions = `1×3 + 2×2 + 3×1`

Final Answer = **4** ✅

---

## Final Notes 📝

* Works efficiently for large inputs
* Common interview + GFG problem
* Similar to **Sum of Subarray Minimums / Maximums**

If you want **dry run**, **Python/Java version**, or **visual stack explanation**, just say the word 👍
