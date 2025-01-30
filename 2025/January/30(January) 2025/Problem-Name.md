# N-Queens Problem

## Description
The **N-Queens problem** is a classic backtracking algorithm challenge where we place `N` queens on an `N x N` chessboard such that no two queens attack each other. This means that no two queens should be in the same row, same column, or on the same diagonal.

## Problem Statement
Given an integer `N`, find all distinct solutions to the N-Queens puzzle. Each solution should be represented as a permutation of `[1, 2, 3, ..., N]`, where the number at the `i`th position denotes the row in which the queen is placed in the `i`th column.

### **Example Inputs & Outputs**
#### **Example 1:**
**Input:**
```
n = 1
```
**Output:**
```
[1]
```
**Explanation:** Only one queen can be placed on the board.

#### **Example 2:**
**Input:**
```
n = 4
```
**Output:**
```
[[2, 4, 1, 3], [3, 1, 4, 2]]
```
**Explanation:** There are 2 possible solutions for `n = 4`.

#### **Example 3:**
**Input:**
```
n = 2
```
**Output:**
```
[]
```
**Explanation:** No valid placements for `n = 2`.

## Constraints
- `1 ≤ n ≤ 10`

## Implementation
This repository contains the C++ implementation for solving the **N-Queens** problem using **Backtracking**.

### **Code Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> result;

    bool isSafe(vector<int>& board, int row, int col, int n) {
        for (int i = 0; i < col; i++) {
            if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
                return false;
            }
        }
        return true;
    }

    void solve(int col, vector<int>& board, int n) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        for (int row = 1; row <= n; row++) {
            if (isSafe(board, row, col, n)) {
                board[col] = row;
                solve(col + 1, board, n);
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, 0);
        solve(0, board, n);
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.empty())
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (auto& sol : ans) {
                cout << "[";
                for (int pos : sol) {
                    cout << pos << " ";
                }
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~\n";
    }
    return 0;
}
```

## **Approach**
- We use **Backtracking** to explore all possible board placements.
- The `isSafe()` function ensures queens are not placed in attacking positions.
- The `solve()` function recursively places queens column-wise and backtracks if needed.

## **Complexity Analysis**
- **Time Complexity:** `O(N!)` (Factorial Growth)
- **Space Complexity:** `O(N)` (Stack space for recursion + board storage)


   ```

## **Contributing**
Contributions are welcome! Feel free to submit a PR if you have optimizations or improvements.

## **License**
This project is licensed under the MIT License.

