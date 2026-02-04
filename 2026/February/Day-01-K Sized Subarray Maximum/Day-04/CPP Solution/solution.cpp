class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        // Left moving ants → time = position
        for (int x : left) {
            ans = max(ans, x);
        }

        // Right moving ants → time = n - position
        for (int x : right) {
            ans = max(ans, n - x);
        }

        return ans;
    }
};
