class Solution {
  public:
    vector<vector<int>> result;  // Stores all valid solutions

    // Utility function to check if placing a queen at (row, col) is safe
    bool isSafe(vector<int>& board, int row, int col, int n) {
        for (int i = 0; i < col; i++) {
            if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
                return false;  // Same row or same diagonal
            }
        }
        return true;
    }

    // Recursive function to solve N-Queens using backtracking
    void solve(int col, vector<int>& board, int n) {
        if (col == n) {  // If all queens are placed
            result.push_back(board);
            return;
        }
        for (int row = 1; row <= n; row++) {
            if (isSafe(board, row, col, n)) {
                board[col] = row;
                solve(col + 1, board, n);  // Recur for next column
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, 0);  // Initialize board representation
        solve(0, board, n);
        return result;
    }
};
