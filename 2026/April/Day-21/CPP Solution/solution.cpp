class Solution {
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        // Prefix sum array
        vector<long long> prefix(n);
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        vector<int> result;
        
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            long long sum = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
            int len = r - l + 1;
            
            result.push_back(sum / len); // floor automatically
        }
        
        return result;
    }
};
