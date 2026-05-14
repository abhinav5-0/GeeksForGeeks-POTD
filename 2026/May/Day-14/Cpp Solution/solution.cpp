class Solution {
public:
    vector<int> search(vector<int>& a, vector<int>& b) {
        vector<int> ans;

        int n = a.size();
        int m = b.size();

        for (int i = 0; i <= n - m; i++) {
            bool found = true;

            for (int j = 0; j < m; j++) {
                if (a[i + j] != b[j]) {
                    found = false;
                    break;
                }
            }

            if (found)
                ans.push_back(i);
        }

        return ans;
    }
};
