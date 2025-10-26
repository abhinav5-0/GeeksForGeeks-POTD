#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // Use a min-heap (priority queue with smallest element on top)
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        
        int totalCost = 0;
        
        // Keep connecting ropes until only one rope remains
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            
            int cost = first + second;
            totalCost += cost;
            
            // Push the new rope back into the heap
            pq.push(cost);
        }
        
        return totalCost;
    }
};
