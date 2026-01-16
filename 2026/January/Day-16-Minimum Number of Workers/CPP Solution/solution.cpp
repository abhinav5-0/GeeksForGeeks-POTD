class Solution {
  public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Create intervals
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int start = max(0, i - arr[i]);
                int end = min(n - 1, i + arr[i]);
                intervals.push_back({start, end});
            }
        }

        // Sort by start
        sort(intervals.begin(), intervals.end());

        int cnt = 0;
        int i = 0;
        int covered = 0;

        // Greedy interval covering
        while(covered < n) {
            int farthest = covered;

            while(i < intervals.size() && intervals[i].first <= covered) {
                farthest = max(farthest, intervals[i].second + 1);
                i++;
            }

            if(farthest == covered)
                return -1;  // gap found

            cnt++;
            covered = farthest;
        }

        return cnt;
    }
};
