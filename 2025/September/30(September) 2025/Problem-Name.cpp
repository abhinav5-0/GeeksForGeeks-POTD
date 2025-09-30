#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> result;
        string s = "";
        generateBinaryStrings(n, s, result);
        return result;
    }

private:
    void generateBinaryStrings(int n, string &s, vector<string> &result) {
        if (s.length() == n) {
            result.push_back(s);
            return;
        }
        s.push_back('0');
        generateBinaryStrings(n, s, result);
        s.pop_back();

        s.push_back('1');
        generateBinaryStrings(n, s, result);
        s.pop_back();
    }
};

// Example usage
int main() {
    Solution sol;
    int n = 3;
    vector<string> ans = sol.binstr(n);
    for (auto &str : ans) cout << str << " ";
    return 0;
}
