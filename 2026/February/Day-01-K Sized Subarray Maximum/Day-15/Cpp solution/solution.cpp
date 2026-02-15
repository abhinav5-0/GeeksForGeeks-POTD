#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& arr, int m) {
        int n = arr.size();
        
        if (m == 0 || n == 0 || m > n)
            return 0;
        
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};
