#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // Min heap to store k+1 elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = arr.size();
        int index = 0; // To place sorted elements back into arr

        // Step 1: Push first k+1 elements into the minHeap
        for (int i = 0; i <= k && i < n; i++) {
            minHeap.push(arr[i]);
        }

        // Step 2: For remaining elements, extract min and push next element
        for (int i = k + 1; i < n; i++) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        // Step 3: Extract remaining elements from heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
