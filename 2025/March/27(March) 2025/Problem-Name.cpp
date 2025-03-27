class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Sort the arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n = arr.size();
        
        int platformCount = 1;  // At least one platform is needed
        int result = 1;
        
        int i = 1;  // Pointer for arrival times
        int j = 0;  // Pointer for departure times
        
        // Process all the trains
        while (i < n && j < n) {
            // If the next event is an arrival and it comes before the next departure
            if (arr[i] <= dep[j]) {
                platformCount++;
                i++;
            }
            // If the next event is a departure, we free a platform
            else {
                platformCount--;
                j++;
            }
            
            // Update the result with the maximum platforms required
            result = max(result, platformCount);
        }
        
        return result;
    }
};
