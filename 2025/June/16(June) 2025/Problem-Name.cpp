class Solution {
  public:
    long long totalCost(vector<int>& heights, vector<int>& cost, int targetHeight) {
        long long total = 0;
        for (int i = 0; i < heights.size(); i++) {
            total += 1LL * abs(heights[i] - targetHeight) * cost[i];
        }
        return total;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
        long long ans = LLONG_MAX;

        while (low <= high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            long long cost1 = totalCost(heights, cost, mid1);
            long long cost2 = totalCost(heights, cost, mid2);

            ans = min({ans, cost1, cost2});

            if (cost1 < cost2) {
                high = mid2 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return (int)ans;
    }
};
