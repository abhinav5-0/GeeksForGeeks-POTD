class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char, int> charCount;
        int left = 0, right = 0, max_len = -1;

        while (right < n) {
            // Add the current character to the map
            charCount[s[right]]++;

            // Shrink the window if there are more than k unique characters
            while (charCount.size() > k) {
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                left++;
            }

            // If we have exactly k unique characters, check window size
            if (charCount.size() == k) {
                max_len = max(max_len, right - left + 1);
            }

            right++;
        }

        return max_len;
    }
};
