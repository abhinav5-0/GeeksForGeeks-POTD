# 🔥 Max XOR Subarray of Size K

## 🧩 Problem Statement

Given an array of integers `arr[]` and a number `k`, find the **maximum XOR** of any **contiguous subarray of size `k`**.

> A subarray is a continuous part of the array.

---

## 🧠 Key Insight

Since the subarray size is **fixed**, we can use the **Sliding Window technique** along with the properties of XOR:

* `a ^ a = 0`
* XOR allows us to **remove** and **add** elements efficiently

So instead of recalculating XOR for every subarray, we update it in **O(1)** time while sliding the window.

---

## 🚀 Approach (Sliding Window XOR)

1. Compute XOR of the **first `k` elements**
2. Store it as the initial answer
3. Slide the window one step at a time:

   * Remove left element using XOR
   * Add new right element using XOR
   * Update maximum answer

---

## ✏️ Example

**Input:**

```
arr = [2, 5, 8, 1, 1, 3], k = 3
```

**Subarrays & XOR:**

* [2, 5, 8] → 15
* [5, 8, 1] → 12
* [8, 1, 1] → 8
* [1, 1, 3] → 3

✅ **Answer = 15**

---

## 💻 C++ Solution (Optimized)

```cpp
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int xr = 0;

        // XOR of first window
        for(int i = 0; i < k; i++) {
            xr ^= arr[i];
        }

        int ans = xr;

        // Sliding window
        for(int i = k; i < arr.size(); i++) {
            xr ^= arr[i - k]; // remove left element
            xr ^= arr[i];     // add right element
            ans = max(ans, xr);
        }

        return ans;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## 🎯 Interview Tip

> Fixed-size subarray + XOR ⇒ Sliding Window works perfectly because XOR cancels out repeated elements.

---

⭐ If this helped you, consider **upvoting** and checking out more optimized solutions on my GitHub!
