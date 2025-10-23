#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store (distance, point)
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            int dist = x * x + y * y; // squared distance

            // Push current point into heap
            maxHeap.push({dist, {x, y}});

            // If heap size exceeds k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        // Extract k closest points from heap
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto it = maxHeap.top();
            maxHeap.pop();
            ans.push_back({it.second.first, it.second.second});
        }

        return ans;
    }
};
