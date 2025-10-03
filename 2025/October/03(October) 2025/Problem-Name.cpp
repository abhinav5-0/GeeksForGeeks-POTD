#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        // Mapping digits to corresponding letters
        vector<string> mapping = {
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        vector<string> result;
        string current = "";

        function<void(int)> backtrack = [&](int idx) {
            if (idx == arr.size()) {
                result.push_back(current);
                return;
            }

            int digit = arr[idx];
            for (char c : mapping[digit]) {
                current.push_back(c);
                backtrack(idx + 1);
                current.pop_back(); // backtrack
            }
        };

        if (!arr.empty()) backtrack(0);
        return result;
    }
};
