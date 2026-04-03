# Print Diagonally

## 🧩 Problem Statement

Given an **n × n** square matrix `mat[][]`, return all the elements of its **anti-diagonals** from **top to bottom**.

---

## 🧪 Examples

### Example 1

```
Input:
n = 2
mat[][] = [[1, 2],
           [3, 4]]

Output:
[1, 2, 3, 4]
```

### Example 2

```
Input:
n = 3
mat[][] = [[1, 2, 3],
           [4, 5, 6],
           [7, 8, 9]]

Output:
[1, 2, 4, 3, 5, 7, 6, 8, 9]
```

---

## 📌 Explanation

* Traverse the matrix **diagonally (anti-diagonals)**.
* First, start from each column of the **first row**.
* Then, start from each row of the **last column**.
* For each starting point, move **down-left** (i++, j--).

---

## ⚙️ Approach

1. Traverse from first row (0, col)
2. Traverse from last column (row, n-1)
3. For each starting point:

   * Collect elements while indices are valid

---

## ⏱️ Complexity

* **Time Complexity:** O(n²)
* **Space Complexity:** O(1) (excluding output array)

---

## 💻 C++ Code

```cpp
class Solution {
public:
    vector<int> diagView(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> res;

        // Traverse first row
        for (int col = 0; col < n; col++) {
            int i = 0, j = col;
            while (i < n && j >= 0) {
                res.push_back(mat[i][j]);
                i++; j--;
            }
        }

        // Traverse last column (excluding first row)
        for (int row = 1; row < n; row++) {
            int i = row, j = n - 1;
            while (i < n && j >= 0) {
                res.push_back(mat[i][j]);
                i++; j--;
            }
        }

        return res;
    }
};
```

---

## 💻 Java Code

```java
class Solution {
    public ArrayList<Integer> diagView(int[][] mat) {
        int n = mat.length;
        ArrayList<Integer> res = new ArrayList<>();

        // First row
        for (int col = 0; col < n; col++) {
            int i = 0, j = col;
            while (i < n && j >= 0) {
                res.add(mat[i][j]);
                i++; j--;
            }
        }

        // Last column
        for (int row = 1; row < n; row++) {
            int i = row, j = n - 1;
            while (i < n && j >= 0) {
                res.add(mat[i][j]);
                i++; j--;
            }
        }

        return res;
    }
}
```

---

## 💻 Python Code

```python
class Solution:
    def diagView(self, mat):
        n = len(mat)
        res = []

        # First row
        for col in range(n):
            i, j = 0, col
            while i < n and j >= 0:
                res.append(mat[i][j])
                i += 1
                j -= 1

        # Last column
        for row in range(1, n):
            i, j = row, n - 1
            while i < n and j >= 0:
                res.append(mat[i][j])
                i += 1
                j -= 1

        return res
```

---

## 📝 Notes

* Anti-diagonal means elements with same `i + j`.
* Order matters: top to bottom traversal.
