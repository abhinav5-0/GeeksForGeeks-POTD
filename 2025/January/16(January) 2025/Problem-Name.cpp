class Solution {
public:
    int maxLen(vector<int> &arr) {
        for (int &x : arr) {
            if (x == 0) x = -1;
        }

        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if (prefixSum == 0) {
                maxLength = max(maxLength, i + 1);
            }

            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
            } else {
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};
