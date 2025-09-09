class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // Step 1: Sort both arrays
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int n = mices.size();
        int maxTime = 0;
        
        // Step 2: Pair ith mouse with ith hole
        for(int i = 0; i < n; i++) {
            maxTime = max(maxTime, abs(mices[i] - holes[i]));
        }
        
        return maxTime;
    }
};
