class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mp;
        
        int left = 0;
        int maxLen = -1;
        
        for(int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            
            while(mp.size() > k) {
                mp[s[left]]--;
                if(mp[s[left]] == 0)
                    mp.erase(s[left]);
                left++;
            }
            
            if(mp.size() == k)
                maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
