class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> dp, sums;
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int x : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            int idx = it - dp.begin();
            if (it == dp.end()) {
                dp.push_back(x);
                sums.push_back((sums.empty() ? 0 : sums.back()) + x);
            } else {
                *it = x;
                sums[idx] = (idx ? sums[idx - 1] : 0) + x;
            }
        }
        return total - sums.back();
    }
};
