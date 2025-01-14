class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap;
        int currentSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];

            if (currentSum == k) {
                maxLength = i + 1;
            }

            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[currentSum - k]);
            }

            if (prefixSumMap.find(currentSum) == prefixSumMap.end()) {
                prefixSumMap[currentSum] = i;
            }
        }

        return maxLength;
    }
};
