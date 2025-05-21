# 🫮 Kth Smallest Number in Multiplication Table

### 📌 Problem Statement

Given three integers `m`, `n`, and `k`, consider a multiplication table of size `m x n`, where:

```
mat[i][j] = i * j   (1-based indexing)
```

Your task is to **return the `k`th smallest element** in this table.

---

### 🧠 Example 1:

**Input:**

```
m = 3, n = 3, k = 5
```

**Multiplication Table:**

```
1 2 3
2 4 6
3 6 9
```

**Output:**

```
3
```

**Explanation:**
The sorted elements are `[1, 2, 2, 3, 3, 4, 6, 6, 9]`. The 5th smallest element is `3`.

---

### 🧠 Example 2:

**Input:**

```
m = 2, n = 3, k = 6
```

**Multiplication Table:**

```
1 2 3
2 4 6
```

**Output:**

```
6
```

**Explanation:**
Sorted elements: `[1, 2, 2, 3, 4, 6]`. The 6th smallest is `6`.

---

### ✅ Constraints

* `1 <= m, n <= 30,000`
* `1 <= k <= m * n`

---

### 🧙‍♂️ Approach

Use **Binary Search** to efficiently find the `k`th smallest element without building the entire table.

#### Key Idea:

For a value `x`, count how many numbers in the table are ≤ `x`.
This count can be used to guide binary search.

#### Count Function:

For each row `i`:

```
count += min(x // i, n)
```

---

### 💻 C++ Code

```cpp
class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        auto countLessEqual = [&](int x) {
            int count = 0;
            for (int i = 1; i <= m; ++i) {
                count += std::min(x / i, n);
            }
            return count;
        };

        int low = 1, high = m * n, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countLessEqual(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```

---

### ⏱️ Complexity

* **Time Complexity:** `O(m * log(m * n)`
* **Space Complexity:** `O(1)`

---

### 🎯 Tags

`Binary Search`, `Matrix`, `Math`, `Hard`
