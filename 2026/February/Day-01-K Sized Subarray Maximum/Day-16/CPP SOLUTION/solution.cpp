class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        // Sort meetings based on starting time
        sort(arr.begin(), arr.end());
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i][0] < arr[i-1][1]) {
                return false; // Overlapping
            }
        }
        
        return true; // No overlapping
    }
};
