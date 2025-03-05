class Solution {
  public:
    static bool compare(const string &a, const string &b) {
        return a.length() < b.length();
    }
    
    bool isPredecessor(const string &a, const string &b) {
        if (a.length() + 1 != b.length()) return false;
        int i = 0, j = 0;
        bool inserted = false;
        while (j < b.length()) {
            if (i < a.length() && a[i] == b[j]) {
                i++;
            } else {
                if (inserted) return false;
                inserted = true;
            }
            j++;
        }
        return true;
    }
    
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int maxLength = 1;
        
        for (const string &word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); i++) {
                string prevWord = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prevWord) != dp.end()) {
                    dp[word] = max(dp[word], dp[prevWord] + 1);
                }
            }
            maxLength = max(maxLength, dp[word]);
        }
        return maxLength;
    }
};
