class Solution {
  public:
    int substrCount(string &s, int k) {
        if (k > s.size()) return 0;

        unordered_map<char, int> freq;
        int count = 0;

        // Initialize the first window
        for (int i = 0; i < k; ++i) {
            freq[s[i]]++;
        }

        if (freq.size() == k - 1) count++;

        // Slide the window
        for (int i = k; i < s.size(); ++i) {
            // Remove the leftmost character of the previous window
            char out_char = s[i - k];
            freq[out_char]--;
            if (freq[out_char] == 0) {
                freq.erase(out_char);
            }

            // Add the new character
            char in_char = s[i];
            freq[in_char]++;

            if (freq.size() == k - 1) count++;
        }

        return count;
    }
};
