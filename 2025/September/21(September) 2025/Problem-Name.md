# 📘 Max Rectangle in a Binary Matrix

## 🔍 Problem Statement
You are given a 2D binary matrix `mat[ ][ ]`, where each cell contains either `0` or `1`. Your task is to find the maximum area of a rectangle that can be formed using only `1's` within the matrix.

### Example 1:
**Input:**
```text
mat = [[0, 1, 1, 0],
       [1, 1, 1, 1],
       [1, 1, 1, 1],
       [1, 1, 0, 0]]
```
**Output:**
```text
8
```
**Explanation:**
The largest rectangle is from (1, 0) to (2, 3):
```
[1, 1, 1, 1]
[1, 1, 1, 1]
```
Area = 4 × 2 = 8.

---

### Example 2:
**Input:**
```text
mat = [[0, 1, 1],
       [1, 1, 1],
       [0, 1, 1]]
```
**Output:**
```text
6
```
**Explanation:**
The largest rectangle is from (0, 1) to (2, 2):
```
[1, 1]
[1, 1]
[1, 1]
```
Area = 2 × 3 = 6.

---

## ✅ Constraints
- `1 ≤ mat.size(), mat[0].size() ≤ 1000`
- `0 ≤ mat[i][j] ≤ 1`

---

## 💡 Approach
This problem can be solved using the **Largest Rectangle in Histogram** technique.

1. Treat each row of the matrix as the base of a histogram.
2. Maintain an array `heights[]` where:
   - If `mat[i][j] == 1`, increment `heights[j]`.
   - If `mat[i][j] == 0`, reset `heights[j] = 0`.
3. For each row, calculate the largest rectangle area using a **monotonic stack**.
4. Keep track of the maximum area across all rows.

⏱️ Time Complexity: **O(n × m)**

---

## 📝 C++ Implementation
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        vector<int> heights(m, 0);
        int maxRect = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) heights[j] += 1;
                else heights[j] = 0;
            }
            maxRect = max(maxRect, largestRectangleArea(heights));
        }
        return maxRect;
    }
};
```

---

## 🔎 Dry Run Example
For `mat = [[0,1,1],[1,1,1],[0,1,1]]`:
- Row 0 → heights = [0,1,1], max area = 2
- Row 1 → heights = [1,2,2], max area = 6
- Row 2 → heights = [0,3,3], max area = 6

✔️ Final Answer = 6
