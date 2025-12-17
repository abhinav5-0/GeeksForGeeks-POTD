class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        if (arr.empty()) return {};
        
        // Step 1: Sort intervals by start time
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> result;
        result.push_back(arr[0]);
        
        // Step 2: Merge overlapping intervals
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] <= result.back()[1]) {
                // Overlapping case
                result.back()[1] = max(result.back()[1], arr[i][1]);
            } else {
                // Non-overlapping case
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};
