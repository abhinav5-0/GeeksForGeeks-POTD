# Gas Station Problem

## Problem Statement
You are given two integer arrays:
- `gas[]`: The amount of gas available at each station.
- `cost[]`: The cost required to travel to the next station.

The goal is to determine if there exists a starting gas station index such that you can complete the circuit without running out of gas. If a valid starting station exists, return its index; otherwise, return `-1`.

## Constraints
- `1 ≤ gas.size(), cost.size() ≤ 10^6`
- `1 ≤ gas[i], cost[i] ≤ 10^3`

## Approach
1. Compute `totalGas` and `totalCost`:
   - If `totalGas < totalCost`, return `-1` as completing the circuit is impossible.
2. Traverse through the stations:
   - Maintain a `tank` variable to track the remaining gas.
   - If `tank` becomes negative at any point, reset `start` to `i + 1` and reset `tank`.

This ensures that we find the correct starting station in `O(n)` time complexity.

## Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0, totalCost = 0, start = 0, tank = 0;
        int n = gas.size();
        
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        
        return (totalGas >= totalCost) ? start : -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    
    while (t--) {
        vector<int> gas, cost;
        string input1, input2;
        
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        
        Solution ob;
        int ans = ob.startStation(gas, cost);
        cout << ans << endl;
    }
    
    return 0;
}
```

## Complexity Analysis
- **Time Complexity**: `O(n)` (single pass through the array)
- **Space Complexity**: `O(1)` (only a few integer variables used)
