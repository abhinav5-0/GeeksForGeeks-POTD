#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minValue(string &s, int k) {
        unordered_map<char, int> freq;
        
        // Step 1: Count frequency
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Create max heap of frequencies
        priority_queue<int> maxHeap;
        for (auto &entry : freq) {
            maxHeap.push(entry.second);
        }

        // Step 3: Remove k characters greedily
        while (k-- && !maxHeap.empty()) {
            int top = maxHeap.top();
            maxHeap.pop();
            if (top > 1)
                maxHeap.push(top - 1);
        }

        // Step 4: Calculate the final value
        int result = 0;
        while (!maxHeap.empty()) {
            int val = maxHeap.top();
            maxHeap.pop();
            result += val * val;
        }

        return result;
    }
};
