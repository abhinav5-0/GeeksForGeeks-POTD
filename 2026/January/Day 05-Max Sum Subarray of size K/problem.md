# Max Sum Subarray of Size K

## 🧩 Problem Statement

Given an array of integers `arr[]` and a number `k`, return the **maximum sum** of a **subarray of size k**.

> **Note:** A subarray is a **contiguous (continuous)** part of the array.

---

## 📌 Examples

### Example 1

**Input:**

```
arr = [100, 200, 300, 400]
k = 2
```

**Output:**

```
700
```

**Explanation:**
Subarrays of size 2 are:

* [100, 200] → sum = 300
* [200, 300] → sum = 500
* [300, 400] → sum = 700 ✅ (maximum)

---

### Example 2

**Input:**

```
arr = [1, 4, 2, 10, 23, 3, 1, 0, 20]
k = 4
```

**Output:**

```
39
```

---

### Example 3

**Input:**

```
arr = [100, 200, 300, 400]
k = 1
```

**Output:**

```
400
```

---

## 🚫 Common Mistake

❌ Sorting the array

Sorting **breaks the original order**, and since subarrays must be **contiguous**, sorting is **not allowed**.

---

## 🧠 Optimal Approach: Sliding Window

### Idea (Simple Words)

* First, calculate the sum of the **first `k` elements**.
* Then, **slide the window** one step at a time:

  * **Remove** the leftmost element of the window
  * **Add** the next element on the right
* Keep updating the **maximum sum**.

This avoids recalculating the sum again and again.

---

## 🔁 Visualization

For:

```
arr = [100, 200, 300, 400]
k = 2
```

* First window: [100, 200] → sum = 300
* Slide window:

  * Remove 100, add 300 → sum = 500
* Slide window:

  * Remove 200, add 400 → sum = 700 ✅

---

## 👨‍💻 C++ Solution (Accepted on GFG)

```cpp
class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;

        // Sum of first window of size k
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int maxSum = sum;

        // Sliding the window
        for (int i = k; i < n; i++) {
            sum = sum + arr[i] - arr[i - k];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## ⭐ Key Takeaways

* Subarray means **continuous elements**
* Never sort in subarray problems
* Sliding Window is best when **fixed size `k`** is given
* Formula to remember:

```
newSum = oldSum + incomingElement - outgoingElement
```

---

✅ This is a classic and very important problem for interviews and coding platforms.
