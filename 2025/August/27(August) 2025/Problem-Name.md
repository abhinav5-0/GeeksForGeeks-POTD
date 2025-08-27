# Count the Number of Possible Triangles

### Problem Statement
Given an integer array `arr[]`. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. A triangle with three given sides is only possible if the sum of any two sides is always greater than the third side.

### Examples
**Input:**
```cpp
arr[] = [4, 6, 3, 7]
```
**Output:**
```
3
```
**Explanation:**
The possible triangles are `[3, 4, 6]`, `[4, 6, 7]`, and `[3, 6, 7]`. `[3, 4, 7]` is not possible because `3+4 = 7` is not strictly greater.

---

**Input:**
```cpp
arr[] = [10, 21, 22, 100, 101, 200, 300]
```
**Output:**
```
6
```
**Explanation:**
Valid triangles are: `[10, 21, 22]`, `[21, 100, 101]`, `[22, 100, 101]`, `[10, 100, 101]`, `[100, 101, 200]`, `[101, 200, 300]`.

---

**Input:**
```cpp
arr[] = [1, 2, 3]
```
**Output:**
```
0
```
**Explanation:**
No triangles possible.

---

### Constraints
- `1 ≤ arr.size() ≤ 10^3`
- `0 ≤ arr[i] ≤ 10^5`

---

### Approach
1. **Sort the array**.
2. Fix the **largest side** one by one (`arr[k]`).
3. Use **two pointers** (`i` and `j`) to find pairs `(i, j)` such that:
   - If `arr[i] + arr[j] > arr[k]`, then all pairs from `i..j-1` with `j` are valid.
   - Else, move `i++`.
4. Count all valid triplets.

This reduces complexity to **O(n²)**.

---

### C++ Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        sort(arr.begin(), arr.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
```

---

### Complexity Analysis
- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

### Key Insight
By sorting, the triangle inequality check reduces to just `arr[i] + arr[j] > arr[k]`, making the problem solvable in quadratic time.
