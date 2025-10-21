#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // Custom comparator for priority queue
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second)
                return a.first < b.first;  // larger number first if freq same
            return a.second < b.second;    // higher frequency first
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for (auto &p : freq) {
            pq.push({p.first, p.second});
        }
        
        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};

// Example usage:
int main() {
    Solution obj;
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1};
    int k = 2;
    vector<int> ans = obj.topKFreq(arr, k);
    
    for (int x : ans) cout << x << " ";
    return 0;
}
