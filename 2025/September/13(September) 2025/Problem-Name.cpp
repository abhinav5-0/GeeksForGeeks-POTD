class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort in descending order
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int i = 0, j = 0;
        int horizontal_segments = 1, vertical_segments = 1;
        long long total_cost = 0;

        // Greedy cutting
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                total_cost += (long long)x[i] * horizontal_segments;
                vertical_segments++;
                i++;
            } else {
                total_cost += (long long)y[j] * vertical_segments;
                horizontal_segments++;
                j++;
            }
        }

        // Remaining vertical cuts
        while (i < x.size()) {
            total_cost += (long long)x[i] * horizontal_segments;
            vertical_segments++;
            i++;
        }

        // Remaining horizontal cuts
        while (j < y.size()) {
            total_cost += (long long)y[j] * vertical_segments;
            horizontal_segments++;
            j++;
        }

        return (int)total_cost;
    }
};
