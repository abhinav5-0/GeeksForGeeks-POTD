#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;  
        k %= n;  // Optimize rotations

        if (type == 1) {
            // Right rotation: move last k elements to front
            for (int i = 0; i < k; i++) {
                int val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            }
        } 
        else if (type == 2) {
            // Left rotation: move first k elements to back
            for (int i = 0; i < k; i++) {
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
        }
    }
};
