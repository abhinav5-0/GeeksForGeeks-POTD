class Solution {
public:
    int longestSubstr(string& s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, result = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If more than k replacements needed, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
