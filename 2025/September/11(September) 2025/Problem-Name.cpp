class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;
        
        int maxReach = arr[0];   // farthest we can reach
        int steps = arr[0];      // steps we can take in current jump
        int jumps = 1;           // we must take at least one jump
        
        for (int i = 1; i < n; i++) {
            // If we've reached the last index
            if (i == n - 1) return jumps;
            
            maxReach = max(maxReach, i + arr[i]);
            steps--;  // used a step
            
            // If no steps left, must do a jump
            if (steps == 0) {
                jumps++;
                // If current index is >= maxReach, we are stuck
                if (i >= maxReach) return -1;
                steps = maxReach - i;
            }
        }
        
        return -1;
    }
};
