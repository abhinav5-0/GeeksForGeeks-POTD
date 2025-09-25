#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        if (n <= 0) return res;
        res.reserve(n);

        queue<string> q;
        q.push("1");

        while ((int)res.size() < n) {
            string s = q.front(); q.pop();
            res.push_back(s);

            // generate next two binary numbers
            q.push(s + "0");
            q.push(s + "1");
        }

        return res;
    }
};

// Example usage (for local testing):
// int main() {
//     Solution sol;
//     int n = 6;
//     vector<string> ans = sol.generateBinary(n);
//     for (auto &b : ans) cout << b << '\n';
// }
