# Count Subarrays with Exactly K Odd Numbers

## 🧩 Problem Statement

You are given an array `arr[]` of **positive integers** and an integer `k`.
Your task is to **count the number of contiguous subarrays** that contain **exactly `k` odd numbers**.

---

## 📌 Examples

### Example 1

**Input:**

```
arr = [2, 5, 6, 9], k = 2
```

**Output:**

```
2
```

**Explanation:**
Subarrays with exactly 2 odd numbers are:

* `[2, 5, 6, 9]`
* `[5, 6, 9]`

---

### Example 2

**Input:**

```
arr = [2, 2, 5, 6, 9, 2, 11], k = 2
```

**Output:**

```
8
```

**Explanation:**
Valid subarrays are:

```
[2, 2, 5, 6, 9]
[2, 5, 6, 9]
[5, 6, 9]
[2, 2, 5, 6, 9, 2]
[2, 5, 6, 9, 2]
[5, 6, 9, 2]
[6, 9, 2, 11]
[9, 2, 11]
```

---

## 🚀 Efficient Approach (Sliding Window + Prefix Idea)

### 🔑 Key Insight

Instead of checking all subarrays (which would be too slow), we:

1. **Convert the array** into a binary array:

   * `1` if the element is odd
   * `0` if the element is even
2. The problem reduces to:

   > Count subarrays with sum exactly `k`
3. This can be solved efficiently using a **prefix sum frequency map**.

---

## 🧠 Algorithm Steps

1. Initialize:

   * `prefixSum = 0`
   * `count = 0`
   * A hashmap to store frequency of prefix sums
2. Traverse the array:

   * Add `1` to `prefixSum` if the element is odd
   * If `(prefixSum - k)` exists in the map, add its frequency to `count`
   * Update the map with the current `prefixSum`

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

Efficient enough for constraints up to `10^5` ✅

---

## 💡 Why This Works

* Each prefix sum represents the number of odd elements seen so far.
* If two prefix sums differ by `k`, the subarray between them has exactly `k` odd numbers.

---

## 🏁 Conclusion

This problem is a classic application of **prefix sums + hashing**, often seen in sliding window problems.

👉 If this explanation helped you, consider **upvoting** ⭐ — it motivates me to share more clean and optimized solutions!

Happy Coding 🚀
