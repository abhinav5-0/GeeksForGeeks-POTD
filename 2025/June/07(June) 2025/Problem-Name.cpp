class Solution {
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vector<int> diff(n);
        
        // Create difference array
        for (int i = 0; i < n; i++) {
            diff[i] = a1[i] - a2[i];
        }
        
        unordered_map<int, int> prefixSumIndex;
        int maxLength = 0;
        int prefixSum = 0;
        
        for (int i = 0; i < n; i++) {
            prefixSum += diff[i];
            
            if (prefixSum == 0) {
                // From start to i, sum is zero
                maxLength = i + 1;
            } else {
                // If prefixSum seen before, calculate subarray length
                if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                    int length = i - prefixSumIndex[prefixSum];
                    if (length > maxLength) {
                        maxLength = length;
                    }
                } else {
                    // Store earliest index of prefixSum
                    prefixSumIndex[prefixSum] = i;
                }
            }
        }
        
        return maxLength;
    }
};
