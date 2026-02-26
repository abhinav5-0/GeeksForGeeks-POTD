class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return false;
        
        vector<int> map1(256, -1);
        vector<int> map2(256, -1);
        
        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            
            if (map1[c1] == -1 && map2[c2] == -1) {
                map1[c1] = c2;
                map2[c2] = c1;
            }
            else if (map1[c1] != c2) {
                return false;
            }
        }
        
        return true;
    }
};
