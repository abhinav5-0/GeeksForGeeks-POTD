class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int n, int k, int start, vector<int>& temp) {
        // If combination is ready
        if (temp.size() == k) {
            if (n == 0) ans.push_back(temp);
            return;
        }

        // Try numbers from 'start' to 9
        for (int i = start; i <= 9; i++) {
            if (i > n) break; // prune search if i > remaining sum

            temp.push_back(i);
            backtrack(n - i, k, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(int n, int k) {
        vector<int> temp;
        backtrack(n, k, 1, temp);
        return ans;
    }
};
