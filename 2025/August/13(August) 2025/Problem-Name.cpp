class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int target = (n + 1) / 2;  // ceil(n/2)

        int alreadyLucky = 0;
        vector<int> costs;

        for (int num : arr) {
            if (num % k == 0) {
                alreadyLucky++;
            } else {
                costs.push_back(k - (num % k));
            }
        }

        // If already enough lucky troops
        if (alreadyLucky >= target) return 0;

        // Sort costs (cheapest conversions first)
        sort(costs.begin(), costs.end());

        int need = target - alreadyLucky;
        int soldiersAdded = 0;

        for (int i = 0; i < need; i++) {
            soldiersAdded += costs[i];
        }

        return soldiersAdded;
    }
};
