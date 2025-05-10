class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int, int> first_occurrence;
        int prefix_sum = 0, max_len = 0;

        for (int i = 0; i < arr.size(); ++i) {
            // Convert to +1 or -1
            prefix_sum += (arr[i] > k) ? 1 : -1;

            // If prefix sum > 0, whole array from 0 to i is valid
            if (prefix_sum > 0)
                max_len = i + 1;
            else {
                // Store first occurrence of prefix sum
                if (first_occurrence.find(prefix_sum) == first_occurrence.end())
                    first_occurrence[prefix_sum] = i;

                // Check if we have seen prefix_sum - 1 before
                if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
                    max_len = max(max_len, i - first_occurrence[prefix_sum - 1]);
                }
            }
        }
        return max_len;
    }
};
