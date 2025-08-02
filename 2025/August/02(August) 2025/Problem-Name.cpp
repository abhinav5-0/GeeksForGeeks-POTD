class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> prefixIndex;
        int prefixSum = 0, maxLen = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            // Convert element to +1 / -1 based on comparison with k
            if (arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1;

            // If prefix sum is positive, the whole subarray [0...i] is valid
            if (prefixSum > 0) {
                maxLen = i + 1;
            } 
            // Else, check if we have seen prefixSum - 1 before
            else {
                if (prefixIndex.find(prefixSum - 1) != prefixIndex.end()) {
                    maxLen = max(maxLen, i - prefixIndex[prefixSum - 1]);
                }
            }

            // Store the first occurrence of this prefixSum
            if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
                prefixIndex[prefixSum] = i;
            }
        }
        
        return maxLen;
    }
};
