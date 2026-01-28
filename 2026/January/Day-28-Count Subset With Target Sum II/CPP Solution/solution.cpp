class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        unordered_map<long long, int> mp;

        // Left half subset sums
        for (int mask = 0; mask < (1 << left.size()); mask++) {
            long long sum = 0;
            for (int i = 0; i < left.size(); i++) {
                if (mask & (1 << i))
                    sum += left[i];
            }
            mp[sum]++;
        }

        int ans = 0;

        // Right half subset sums
        for (int mask = 0; mask < (1 << right.size()); mask++) {
            long long sum = 0;
            for (int i = 0; i < right.size(); i++) {
                if (mask & (1 << i))
                    sum += right[i];
            }
            if (mp.count(k - sum))
                ans += mp[k - sum];
        }

        return ans;
    }
};
