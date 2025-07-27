class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool firstRow = false, firstCol = false;

        // Step 1: Mark rows and columns to be zeroed
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 0) firstCol = true;
        }

        for (int j = 0; j < m; ++j) {
            if (mat[0][j] == 0) firstRow = true;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // Step 2: Set matrix cells to 0 using marks
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // Step 3: Update first row if needed
        if (firstRow) {
            for (int j = 0; j < m; ++j) {
                mat[0][j] = 0;
            }
        }

        // Step 4: Update first column if needed
        if (firstCol) {
            for (int i = 0; i < n; ++i) {
                mat[i][0] = 0;
            }
        }
    }
};
