#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(arr.size(), false);

        sort(arr.begin(), arr.end()); // ensure sorted order
        backtrack(arr, result, current, used);
        return result;
    }

private:
    void backtrack(vector<int>& arr, vector<vector<int>>& result,
                   vector<int>& current, vector<bool>& used) {
        if (current.size() == arr.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (used[i]) continue;

            // Skip duplicates: if arr[i] == arr[i-1] and i-1 not used, skip
            if (i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue;

            used[i] = true;
            current.push_back(arr[i]);

            backtrack(arr, result, current, used);

            // backtrack
            current.pop_back();
            used[i] = false;
        }
    }
};
