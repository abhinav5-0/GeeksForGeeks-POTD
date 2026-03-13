class Solution {
public:
    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    vector<string> generateIp(string &s) {
        vector<string> res;
        int n = s.size();

        for (int i = 1; i <= 3 && i < n; i++) {
            for (int j = i + 1; j <= i + 3 && j < n; j++) {
                for (int k = j + 1; k <= j + 3 && k < n; k++) {

                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (d.size() > 3) continue;

                    if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                        res.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }

        return res;
    }
};
