# Mean of Range in Array

## 🧩 Problem Statement

Given an integer array `arr[]` and a 2D array `queries[][]`. Each query `queries[i] = [l, r]` represents a subarray ranging from index `l` to `r` (inclusive).

For every query, compute the **mean (average)** of the elements in the specified range, and return the **floor value** of that mean.

Return an array where each element corresponds to the result of a query.

---

## 📥 Examples

### Example 1

**Input:**
`arr = [1, 2, 3, 4, 5]`
`queries = [[0, 2], [1, 3], [0, 4]]`

**Output:**
`[2, 3, 3]`

**Explanation:**

* Query 1: `[0, 2]` → subarray `[1, 2, 3]` → sum = 6 → mean = 6/3 = 2
* Query 2: `[1, 3]` → subarray `[2, 3, 4]` → sum = 9 → mean = 9/3 = 3
* Query 3: `[0, 4]` → subarray `[1, 2, 3, 4, 5]` → sum = 15 → mean = 15/5 = 3

---

### Example 2

**Input:**
`arr = [6, 7, 8, 10]`
`queries = [[0, 3], [1, 2]]`

**Output:**
`[7, 7]`

**Explanation:**

* Query 1: `[0, 3]` → subarray `[6, 7, 8, 10]` → sum = 31 → mean = 31/4 = 7 (floor)
* Query 2: `[1, 2]` → subarray `[7, 8]` → sum = 15 → mean = 15/2 = 7 (floor)

---

## ⚙️ Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^3`
* `1 ≤ queries.size() ≤ 10^5`
* `0 ≤ l ≤ r < arr.size()`

---

## 💡 Approach (Prefix Sum)

To efficiently compute the sum of any subarray:

1. Build a prefix sum array:

   ```
   prefix[i] = arr[0] + arr[1] + ... + arr[i]
   ```

2. For a query `[l, r]`:

   ```
   sum = prefix[r] - (l > 0 ? prefix[l-1] : 0)
   length = r - l + 1
   mean = sum / length
   ```

3. Store the floor of the mean.

---

## ⏱️ Complexity

* Time Complexity: `O(n + q)`
* Space Complexity: `O(n)`

---

## 🧠 Key Idea

Using prefix sum avoids recomputing sums for every query, making the solution efficient for large inputs.

---

## 🧾 Function Signature (C++)

```cpp
class Solution {
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
    }
};
```
