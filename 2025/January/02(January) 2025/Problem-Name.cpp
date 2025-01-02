class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0;
        int count = 0;

        // Initialize hash map with 0 sum having frequency 1.
        prefixSumCount[0] = 1;

        for (int num : arr) {
            currentSum += num;

            // Check if there's a prefix sum that matches currentSum - k
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Update the frequency of the current sum in the hash map
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
