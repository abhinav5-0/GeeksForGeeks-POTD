class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0, totalCost = 0, start = 0, tank = 0;
        int n = gas.size();
        
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            // If tank becomes negative, reset starting station
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        
        return (totalGas >= totalCost) ? start : -1;
    }
};
