# Find the Peak Element in a 2D Matrix

## 📌 Problem Statement

Given a 2D matrix `mat[][]`, identify **any peak element**.

An element is considered a **peak** if it is **greater than or equal to its four immediate neighbors**:

* Top
* Bottom
* Left
* Right

For **edge and corner elements**, missing neighbors are treated as **negative infinity (-∞)**.

> ⚠️ A peak element is **not necessarily the global maximum**.
> Multiple peak elements may exist — return **any one**.

---

## 🔍 Observations

* A peak **always exists** in a matrix.
* Brute force would take `O(n × m)` which is inefficient for large matrices.
* We can optimize using **Binary Search on Columns**.

---

## 💡 Optimized Approach (Binary Search on Columns)

### Steps:

1. Perform **binary search** on columns.
2. For the middle column:

   * Find the **row index of the maximum element** in that column.
3. Compare this element with its **left and right neighbors**.
4. Decision:

   * If it is greater than or equal to both → **Peak found**
   * If left neighbor is greater → move search to **left half**
   * If right neighbor is greater → move search to **right half**

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n log m)`
* **Space Complexity:** `O(1)`

---

## 🧾 C++ Implementation

```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = m - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Find row index of maximum element in mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1e9;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1e9;
            
            // Check if peak
            if (mat[maxRow][mid] >= left && mat[maxRow][mid] >= right) {
                return {maxRow, mid};
            }
            else if (left > mat[maxRow][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return {-1, -1}; // Will never reach here
    }
};
```

---

## ✅ Example

### Input

```
10  20  15
21  30  14
7   16  32
```

### Output

* Peak at `(1,1)` → **30**
* OR Peak at `(2,2)` → **32**

---

## 📝 Key Takeaways

* Binary search reduces complexity drastically
* Only left & right comparison is enough
* Always return **any valid peak**

---

🎯 **This solution is optimal and accepted on platforms like GFG and Lee
