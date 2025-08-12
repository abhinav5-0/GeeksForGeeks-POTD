class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();

        // Minimum cost
        int minCost = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minCost += prices[i]; // buy cheapest
            i++;
            j -= k; // take k expensive ones for free
        }

        // Maximum cost
        int maxCost = 0;
        i = n - 1, j = 0;
        while (j <= i) {
            maxCost += prices[i]; // buy most expensive
            i--;
            j += k; // take k cheapest for free
        }

        return {minCost, maxCost};
    }
};
