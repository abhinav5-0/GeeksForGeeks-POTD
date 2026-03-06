class Solution {
public:
    string minWindow(string s, string p) {
        vector<int> freq(256, 0);

        for(char c : p)
            freq[c]++;

        int start = 0, start_index = -1;
        int min_len = INT_MAX;
        int count = 0;

        for(int end = 0; end < s.length(); end++) {

            if(freq[s[end]] > 0)
                count--;

            freq[s[end]]--;

            if(count == -p.length()) {
                while(freq[s[start]] < 0) {
                    freq[s[start]]++;
                    start++;
                }

                int len = end - start + 1;
                if(min_len > len) {
                    min_len = len;
                    start_index = start;
                }

                freq[s[start]]++;
                start++;
                count++;
            }
        }

        if(start_index == -1)
            return "";

        return s.substr(start_index, min_len);
    }
};
