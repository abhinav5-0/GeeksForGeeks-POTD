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
