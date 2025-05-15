class Solution {
  public:
    int countSubstring(string &s) {
        int freq[26] = {0};
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int total = 0;
        for (int i = 0; i < 26; ++i) {
            total += (freq[i] * (freq[i] + 1)) / 2;
        }

        return total;
    }
};
