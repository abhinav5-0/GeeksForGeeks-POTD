class Solution {
public:
    bool canFormPalindrome(string &s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0;
        for (int f : freq) {
            if (f % 2 != 0) oddCount++;
        }

        return oddCount <= 1;
    }
};
