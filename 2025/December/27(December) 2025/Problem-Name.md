## Kth Smallest Element in a Sorted Matrix

**Difficulty:** Medium  
**Accuracy:** 61.42%  
**Points:** 4

---

### Problem Statement

Given a matrix `mat[][]` of size `n x n`, where **each row and each column is sorted in non-decreasing order**, find the **kth smallest element** in the matrix.

---

### Examples

**Example 1**

```
Input:
mat = [[16, 28, 60, 64],
       [22, 41, 63, 91],
       [27, 50, 87, 93],
       [36, 78, 87, 94]]
 k = 3

Output: 27
```

**Explanation:** The sorted order of elements gives `27` as the 3rd smallest.

---

**Example 2**

```
Input:
mat = [[10, 20, 30, 40],
       [15, 25, 35, 45],
       [24, 29, 37, 48],
       [32, 33, 39, 50]]
 k = 7

Output: 30
```

---

### Constraints

* `1 ≤ n ≤ 500`
* `1 ≤ mat[i][j] ≤ 10^4`
* `1 ≤ k ≤ n * n`

---

## Approach: Binary Search on Answer

Since rows and columns are sorted, we can apply **binary search on the value range** instead of indices.

### Key Idea

* The smallest element is `mat[0][0]`
* The largest element is `mat[n-1][n-1]`
* For a chosen `mid`, count how many elements are `≤ mid`
* Adjust binary search based on the count

---

### Counting Elements ≤ mid

Start from the **bottom-left corner**:

* If `mat[i][j] ≤ mid`, then all elements above it in the column are also ≤ mid
* Otherwise, move upward

This counting works in **O(n)** time.

---

### Algorithm Steps

1. Initialize `low = mat[0][0]`, `high = mat[n-1][n-1]`
2. While `low < high`:

   * Compute `mid`
   * Count elements `≤ mid`
   * If count < k → move right (`low = mid + 1`)
   * Else → move left (`high = mid`)
3. `low` will be the kth smallest element

---

### C++ Implementation

```cpp
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    int low = mat[0][0], high = mat[n-1][n-1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        int i = n - 1, j = 0;

        while (i >= 0 && j < n) {
            if (mat[i][j] <= mid) {
                count += (i + 1);
                j++;
            } else {
                i--;
            }
        }

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
```

---

### Time & Space Complexity

* **Time Complexity:** `O(n log(max - min))`
* **Space Complexity:** `O(1)`

---

### Summary

* Uses **binary search on value range**
* Efficient for large matrices
* Avoids flattening the matrix

---

✅ This is the optimal and most commonly expected solution in interviews and competitive programming.
