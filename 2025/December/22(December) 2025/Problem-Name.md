# Row with Max 1s

**Difficulty:** Medium
**Accuracy:** 33.09%
**Points:** 4

---

## 🧩 Problem Statement

You are given a **2D binary array `arr[][]`** consisting of only `0`s and `1`s. Each row of the array is **sorted in non-decreasing order**.

Your task is to **find and return the index of the first row that contains the maximum number of `1`s**.

If no row contains any `1`, return `-1`.

---

## 📝 Notes

* The array uses **0-based indexing**
* `n` → number of rows
* `m` → number of columns

---

## 🔍 Examples

### Example 1

**Input:**

```
arr = [[0,1,1,1],
       [0,0,1,1],
       [1,1,1,1],
       [0,0,0,0]]
```

**Output:** `2`
**Explanation:** Row 2 has the maximum number of `1`s (4).

---

### Example 2

**Input:**

```
arr = [[0,0],
       [1,1]]
```

**Output:** `1`

---

### Example 3

**Input:**

```
arr = [[0,0],
       [0,0]]
```

**Output:** `-1`

---

## 💡 Approach (Binary Search)

Since each row is sorted:

* All `0`s appear before `1`s
* The number of `1`s in a row = `m - index_of_first_1`

We use **binary search (`lower_bound`)** to find the first `1` in each row and keep track of the row with the maximum count.

---

## ⚙️ Algorithm

1. Initialize:

   * `maxOnes = 0`
   * `rowIndex = -1`
2. Traverse each row:

   * Use binary search to find the first `1`
   * Calculate the count of `1`s
3. Update the result if a row has more `1`s than the current maximum
4. Return the row index

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();

        int maxOnes = 0;
        int rowIndex = -1;

        for (int i = 0; i < n; i++) {
            int firstOne = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
            int countOnes = m - firstOne;

            if (countOnes > maxOnes) {
                maxOnes = countOnes;
                rowIndex = i;
            }
        }
        return rowIndex;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n log m)`
* **Space Complexity:** `O(1)`

---

## ⭐ Key Takeaway

Binary search is effective here because each row is already sorted, allowing us to efficiently determine the row with the maximum number of `1`s.
