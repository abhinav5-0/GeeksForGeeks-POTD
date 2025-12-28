class Solution {
  public:
    bool canMake(int time, vector<int>& ranks, int n) {
        int total = 0;

        for (int r : ranks) {
            int low = 0, high = n;
            int donuts = 0;

            // Binary search for max donuts this chef can make
            while (low <= high) {
                int mid = (low + high) / 2;
                long long required = 1LL * r * mid * (mid + 1) / 2;

                if (required <= time) {
                    donuts = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            total += donuts;
            if (total >= n) return true;
        }

        return false;
    }

    int minTime(vector<int>& ranks, int n) {
        int minRank = *min_element(ranks.begin(), ranks.end());

        int low = 0;
        int high = minRank * n * (n + 1) / 2;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(mid, ranks, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
