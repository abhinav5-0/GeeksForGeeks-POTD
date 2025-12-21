class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        int n = arr.size();

        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            // Find first index where arr[i] >= x
            int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            // Find first index where arr[i] > x
            int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

            // Restrict to range [l, r]
            int start = max(left, l);
            int end = min(right, r + 1);

            if (start < end)
                result.push_back(end - start);
            else
                result.push_back(0);
        }

        return result;
    }
};
