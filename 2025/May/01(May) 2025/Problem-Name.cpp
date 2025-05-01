class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        const int MOD = 1e9 + 7;
        vector<int> row;
        row.push_back(1);  // First element is always 1
        
        long long prev = 1;
        for (int k = 1; k < n; ++k) {
            // Use the relation to calculate next coefficient
            long long curr = (prev * (n - k)) / k;
            curr %= MOD;
            row.push_back((int)curr);
            prev = curr;
        }
        return row;
    }
};
