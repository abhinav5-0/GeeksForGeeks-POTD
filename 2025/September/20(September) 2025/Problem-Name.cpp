#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n = arr.size();
        int low = 1, high = n, ans = 0;

        auto can = [&](int L) {
            deque<int> dq;
            for (int i = 0; i < n; i++) {
                // maintain deque decreasing
                while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
                dq.push_back(i);

                // remove elements outside window
                if (dq.front() <= i - L) dq.pop_front();

                // check when window size reaches L
                if (i >= L - 1) {
                    if (arr[dq.front()] <= L) return true;
                }
            }
            return false;
        };

        while (low <= high) {
            int mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1; // try bigger
            } else {
                high = mid - 1; // try smaller
            }
        }
        return ans;
    }
};
