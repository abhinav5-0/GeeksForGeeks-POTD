class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;  // Only one tower
        
        sort(arr.begin(), arr.end());  // Step 1: Sort
        
        int ans = arr[n-1] - arr[0];  // Initial difference
        
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;
        
        for (int i = 0; i < n - 1; i++) {
            int min_height = min(smallest, arr[i+1] - k);
            int max_height = max(largest, arr[i] + k);
            
            if (min_height < 0) continue;  // Skip invalid case
            
            ans = min(ans, max_height - min_height);
        }
        
        return ans;
    }
};
