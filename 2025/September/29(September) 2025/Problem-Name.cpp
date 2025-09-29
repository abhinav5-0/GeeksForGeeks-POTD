#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + arr[i];
        }

        deque<int> dq; // store indices of prefix sums
        long long ans = LLONG_MIN;

        for (int r = 0; r < n; r++) {
            // Add new left index for subarray length >= a
            if (r - a + 1 >= 0) {
                int idx = r - a + 1;
                // maintain increasing order of pref values
                while (!dq.empty() && pref[dq.back()] >= pref[idx]) 
                    dq.pop_back();
                dq.push_back(idx);
            }

            // Remove indices that are too far (length > b)
            while (!dq.empty() && dq.front() < r - b + 1) {
                dq.pop_front();
            }

            // If we have valid left index, calculate max sum
            if (!dq.empty()) {
                ans = max(ans, pref[r+1] - pref[dq.front()]);
            }
        }

        return (int)ans;
    }
};
