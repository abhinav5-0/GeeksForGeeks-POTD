# Count Distinct Elements in Every Window

## 🧩 Problem Summary

Given an integer array `arr[]` and an integer `k`, you need to find the number of **distinct elements** in **every contiguous subarray (window)** of size `k`.

---

## 🔍 Example

**Input:**

```
arr = [1, 2, 1, 3, 4, 2, 3]
k = 4
```

**Output:**

```
[3, 4, 4, 3]
```

---

## 💡 Optimal Approach (Sliding Window + Hash Map)

### Idea

* Use a **sliding window** of size `k`.
* Maintain a **frequency map** to store counts of elements in the current window.
* The number of keys in the map represents the number of **distinct elements**.

### Steps

1. Traverse the array from left to right.
2. Add the current element to the frequency map.
3. Once the window size exceeds `k`:

   * Remove the leftmost element from the map.
   * If its frequency becomes `0`, delete it from the map.
4. When the window size is exactly `k`, record the size of the map.

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(k)`

Efficient enough for constraints up to `10^5`.

---

## ✅ C++ Implementation

```cpp
class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        vector<int> result;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;

            if (i >= k) {
                freq[arr[i - k]]--;
                if (freq[arr[i - k]] == 0)
                    freq.erase(arr[i - k]);
            }

            if (i >= k - 1)
                result.push_back(freq.size());
        }
        return result;
    }
};
```

---

## 📝 Key Takeaways

* Sliding Window helps avoid recalculating for every subarray.
* Hash Map ensures quick insert, delete, and lookup.
* This pattern is widely used in window-based array problems.

---

⭐ If this explanation helped you, consider upvoting or starring the solution!
