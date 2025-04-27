class Solution {
  public:
    string multiplyStrings(string& s1, string& s2) {
        // Check if either string is "0"
        auto removeLeadingZeros = [](string &s) {
            int i = 0;
            while (i < s.size() && s[i] == '0') i++;
            s = s.substr(i);
            if (s.empty()) s = "0";
        };
        
        bool isNegative = false;
        if (s1[0] == '-') {
            isNegative = !isNegative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            isNegative = !isNegative;
            s2 = s2.substr(1);
        }
        
        removeLeadingZeros(s1);
        removeLeadingZeros(s2);
        
        if (s1 == "0" || s2 == "0") return "0";
        
        int n = s1.size(), m = s2.size();
        vector<int> result(n + m, 0);
        
        // Multiply each digit and add to result
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        // Convert result array to string
        string ans = "";
        int i = 0;
        while (i < result.size() && result[i] == 0) i++; // skip leading zeros
        
        for (; i < result.size(); i++) {
            ans += (result[i] + '0');
        }
        
        if (isNegative) ans = '-' + ans;
        
        return ans;
    }
};
