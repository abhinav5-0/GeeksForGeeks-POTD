class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> prefix(n + 1, 0); // prefix sum

        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            int x = arr[i] + k;

            // Binary search for the first index where arr[j] > x
            int l = upper_bound(arr.begin() + i, arr.end(), x) - arr.begin();

            long long removeLeft = prefix[i]; // Remove all left piles
            long long removeRight = prefix[n] - prefix[l] - 1LL * x * (n - l); // Reduce higher values to x

            ans = min(ans, removeLeft + removeRight);
        }

        return (int)ans;
    }
};
