# Sudoku Solver

## Description
This repository contains a C++ implementation of a Sudoku solver using backtracking. The program takes a 9x9 Sudoku grid with empty cells represented as `0` and fills in the missing numbers while ensuring all Sudoku rules are met.

## Algorithm
The solution uses **backtracking** to recursively try filling empty cells with numbers from 1 to 9, checking for validity at each step. If a conflict arises, it backtracks and tries the next possibility.

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if placing num at mat[row][col] is valid
    bool isValid(vector<vector<int>> &mat, int row, int col, int num) {
        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (mat[row][i] == num || mat[i][col] == num)
                return false;
        }
        
        // Check 3x3 sub-box
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[startRow + i][startCol + j] == num)
                    return false;
            }
        }
        return true;
    }
    
    // Backtracking function to solve Sudoku
    bool solve(vector<vector<int>> &mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) { // Find empty cell
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) {
                            mat[row][col] = num;
                            if (solve(mat))
                                return true;
                            mat[row][col] = 0; // Backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // Sudoku solved
    }
    
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};

// Driver Code
vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;
        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
```

## How to Run
1. Clone the repository:
   ```sh
   git clone <repository-url>
   cd sudoku_solver
   ```
2. Compile the code:
   ```sh
   g++ sudoku_solver.cpp -o sudoku_solver
   ```
3. Run the program:
   ```sh
   ./sudoku_solver
   ```

## Sample Input
```
1 0 3 0 5 6 0 8 9
0 5 0 8 0 1 3 0 6
9 6 8 0 3 0 5 1 0
8 0 9 0 2 0 6 7 5
0 2 0 6 0 8 0 9 0
5 1 6 0 9 0 8 0 3
0 8 1 0 6 0 9 3 7
7 0 5 1 0 3 0 6 0
3 9 0 7 8 0 1 0 4
```

## Sample Output
```
1 7 3 2 5 6 4 8 9
2 5 4 8 7 1 3 9 6
9 6 8 4 3 9 5 1 2
8 3 9 1 2 4 6 7 5
4 2 7 6 5 8 3 9 1
5 1 6 3 9 7 8 4 3
6 8 1 5 6 2 9 3 7
7 4 5 1 9 3 2 6 8
3 9 2 7 8 5 1 6 4
```



