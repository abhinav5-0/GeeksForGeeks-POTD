class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> ple(n), nle(n);
        stack<int> s;

        // Find Previous Less Element (PLE)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // Find Next Less Element (NLE)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            nle[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate result
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            res = (res + arr[i] * left * right) % MOD;
        }

        return res;
    }
};
