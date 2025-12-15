class Solution {
  public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        
        int totalEven = 0, totalOdd = 0;
        
        // Step 1: total sums
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }
        
        int leftEven = 0, leftOdd = 0;
        int rightEven = totalEven, rightOdd = totalOdd;
        
        int count = 0;
        
        // Step 2: try removing each index
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) rightEven -= arr[i];
            else rightOdd -= arr[i];
            
            // After removal, parity of right side flips
            if (leftEven + rightOdd == leftOdd + rightEven)
                count++;
            
            if (i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }
        
        return count;
    }
};
