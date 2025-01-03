class Solution {
public:
    long subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> freq; // To store frequency of XOR values
        int xorSum = 0;              // Cumulative XOR
        long count = 0;              // Count of subarrays

        // Initialize the map to handle cases where xorSum itself equals k
        freq[0] = 1;

        for (int num : arr) {
            xorSum ^= num; // Update cumulative XOR

            // Check if xorSum ^ k exists in the map
            if (freq.find(xorSum ^ k) != freq.end()) {
                count += freq[xorSum ^ k];
            }

            // Update the frequency map
            freq[xorSum]++;
        }

        return count;
    }
};
