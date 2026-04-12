# Toeplitz Matrix

**Difficulty:** Easy
**Accuracy:** 49.05%
**Submissions:** 49K+
**Points:** 2

---

## Problem Statement

A **Toeplitz matrix** (also known as a diagonal-constant matrix) is a matrix in which every descending diagonal from left to right contains the same element.

Given a rectangular matrix `mat`, determine whether it is a Toeplitz matrix or not.

Implement the function `isToeplitz(mat)` that returns:

* `true` if the matrix is a Toeplitz matrix
* `false` otherwise

---

## Examples

### Example 1

**Input:**

```
mat[][] = [
  [6, 7, 8],
  [4, 6, 7],
  [1, 4, 6]
]
```

**Output:**

```
true
```

**Explanation:**
Each diagonal from top-left to bottom-right has the same elements.

* Main diagonal: 6 → 6 → 6
* Other diagonals: 7 → 7 and 4 → 4

Hence, the matrix is Toeplitz.

---

### Example 2

**Input:**

```
mat[][] = [
  [6, 3, 8],
  [4, 9, 7],
  [1, 4, 6]
]
```

**Output:**

```
false
```

**Explanation:**
The main diagonal elements are 6, 9, 6 which are not equal.

Hence, the matrix is **not** Toeplitz.

---

## Constraints

* 1 ≤ mat.size(), mat[0].size() ≤ 40
* 0 ≤ mat[i][j] ≤ 100

---

## Approach

To check whether a matrix is Toeplitz:

* Compare every element with its top-left neighbor.
* If any element `mat[i][j] != mat[i-1][j-1]`, return `false`.
* If all elements satisfy the condition, return `true`.

---

## Time & Space Complexity

* **Time Complexity:** O(n × m)
* **Space Complexity:** O(1)

---

## Code Implementations

### C++

```cpp
class Solution {
public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][j] != mat[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
};
```

---

### Java

```java
class Solution {
    public boolean isToeplitz(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][j] != mat[i-1][j-1])
                    return false;
            }
        }
        return true;
    }
}
```

---

### Python

```python
class Solution:
    def isToeplitz(self, mat):
        n = len(mat)
        m = len(mat[0])
        
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][j] != mat[i-1][j-1]:
                    return False
        return True
```

---

## Key Insight

A matrix is Toeplitz **iff every element matches its top-left diagonal neighbor**.

---

## Tags

* Matrix
* Arrays
* Implementation
