class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        
        int low = mat[0][0];
        int high = mat[n-1][n-1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            int i = n - 1, j = 0;

            // Count elements <= mid
            while (i >= 0 && j < n) {
                if (mat[i][j] <= mid) {
                    count += (i + 1);
                    j++;
                } else {
                    i--;
                }
            }

            if (count < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
