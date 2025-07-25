class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int maxRight = right.empty() ? 0 : n - *min_element(right.begin(), right.end());
        return max(maxLeft, maxRight);
    }
};
