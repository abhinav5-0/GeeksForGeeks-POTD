class Solution {
public:
    string removeSpaces(string& s) {
        string result = "";
        for(char c : s) {
            if(c != ' ') {
                result += c;
            }
        }
        return result;
    }
};
