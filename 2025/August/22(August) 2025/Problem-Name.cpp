class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 1, high = 2000; // given constraint
        
        int desired = (n * m + 1) / 2;
        
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            
            // count numbers <= mid in each row
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if (count < desired) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};
