class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        vector<int> need(26, 0), window(26, 0);
        for (char c : p) need[c - 'a']++;

        int required = 0; 
        for (int x : need) if (x > 0) required++;

        int formed = 0;
        int left = 0, minLen = INT_MAX, startIdx = -1;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c - 'a']++;

            if (need[c - 'a'] > 0 && window[c - 'a'] == need[c - 'a'])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char d = s[left];
                window[d - 'a']--;
                if (need[d - 'a'] > 0 && window[d - 'a'] < need[d - 'a'])
                    formed--;
                left++;
            }
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};
