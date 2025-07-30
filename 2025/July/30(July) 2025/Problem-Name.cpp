class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int count = 0;
        int prefixSum = 0;

        // Initialize with prefixSum 0 to handle case when subarray starts at index 0
        prefixSumCount[0] = 1;

        for (int num : arr) {
            prefixSum += num;

            // Check if (prefixSum - k) has occurred before
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }

            // Increment frequency of the current prefixSum
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};
