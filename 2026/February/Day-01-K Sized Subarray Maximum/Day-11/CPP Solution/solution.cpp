#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({heights[i], cost[i]});
        }
        
        sort(v.begin(), v.end());
        
        long long totalCost = 0;
        for(int i = 0; i < n; i++)
            totalCost += v[i].second;
        
        // Find weighted median
        long long curr = 0;
        int target = 0;
        for(int i = 0; i < n; i++) {
            curr += v[i].second;
            if(curr >= (totalCost + 1) / 2) {
                target = v[i].first;
                break;
            }
        }
        
        // Calculate minimum cost
        long long answer = 0;
        for(int i = 0; i < n; i++) {
            answer += 1LL * abs(heights[i] - target) * cost[i];
        }
        
        return answer;
    }
};
