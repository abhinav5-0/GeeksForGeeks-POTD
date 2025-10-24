#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        
        for (int num : arr) {
            if (mp.find(num - 1) != mp.end() && !mp[num - 1].empty()) {
                int len = mp[num - 1].top();
                mp[num - 1].pop();
                mp[num].push(len + 1);
            } else {
                mp[num].push(1);
            }
        }

        // Check if all subsequences are of length >= k
        for (auto& [key, pq] : mp) {
            while (!pq.empty()) {
                if (pq.top() < k) return false;
                pq.pop();
            }
        }

        return true;
    }
};
