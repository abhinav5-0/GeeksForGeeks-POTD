#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minOperations(vector<int>& arr) {
        priority_queue<double> pq; // max heap for floating values
        double totalSum = 0;
        
        for (int x : arr) {
            pq.push(x);
            totalSum += x;
        }
        
        double target = totalSum / 2.0;
        double reduced = 0;
        int operations = 0;
        
        while (reduced < target) {
            double largest = pq.top(); pq.pop();
            double half = largest / 2.0;
            
            reduced += half;       // we reduce total sum by half of that element
            pq.push(half);         // push the halved value back
            operations++;
        }
        
        return operations;
    }
};
