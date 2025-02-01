# Word Search Problem (GFG)

## Problem Statement
You are given a two-dimensional `mat[][]` of size `n*m` containing English alphabets and a string `word`. Check if the word exists in the matrix. The word can be constructed using adjacent cells, either **horizontally or vertically**. The **same cell cannot be used more than once**.



## Constraints
- `1 ≤ n, m ≤ 6`
- `1 ≤ L ≤ 15`
- `mat` and `word` consist only of lowercase and uppercase English letters.

---

## **Solution Approach**
The problem is solved using **Depth-First Search (DFS) with Backtracking**.

### **Algorithm**
1. Traverse the entire matrix to find the first character of the word.
2. If found, initiate DFS from that position.
3. Recursively explore all four possible directions (**left, right, up, down**).
4. Ensure a cell is not used more than once by marking it temporarily.
5. Backtrack when the current path fails to form the word.
6. If any DFS call successfully finds the word, return `true`; otherwise, return `false`.

---

## **Code Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        if (index == word.size()) return true;
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] != word[index])
            return false;

        char temp = mat[i][j];
        mat[i][j] = '#'; // Mark as visited

        int rowDir[] = {0, 0, 1, -1};
        int colDir[] = {1, -1, 0, 0};

        for (int d = 0; d < 4; d++) {
            int newRow = i + rowDir[d];
            int newCol = j + colDir[d];
            if (dfs(mat, word, newRow, newCol, index + 1)) 
                return true;
        }

        mat[i][j] = temp; // Backtrack
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        cout << (ans ? "true" : "false") << endl;
    }
    return 0;
}
