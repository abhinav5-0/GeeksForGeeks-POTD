class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();
        int n = arr[0].size();
        
        // Min-heap: stores {value, list index, index in list}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        int currentMax = INT_MIN;
        
        // Initialize heap with first element from each list
        for (int i = 0; i < k; ++i) {
            minHeap.push({arr[i][0], i, 0});
            currentMax = max(currentMax, arr[i][0]);
        }
        
        int rangeStart = 0, rangeEnd = INT_MAX;
        
        while (true) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int currentMin = curr[0];
            int row = curr[1];
            int col = curr[2];
            
            // Update the smallest range if the current one is smaller
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }
            
            // If there is a next element in the same list, add it to heap
            if (col + 1 < n) {
                int nextVal = arr[row][col + 1];
                minHeap.push({nextVal, row, col + 1});
                currentMax = max(currentMax, nextVal);
            } else {
                // If any list is exhausted, we can't continue
                break;
            }
        }
        
        return {rangeStart, rangeEnd};
    }
};
