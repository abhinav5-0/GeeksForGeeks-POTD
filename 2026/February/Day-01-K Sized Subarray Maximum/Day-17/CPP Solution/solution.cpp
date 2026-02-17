class Solution {
public:
    int overlapInt(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<int> start(n), end(n);
        
        for(int i = 0; i < n; i++) {
            start[i] = arr[i][0];
            end[i] = arr[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0;
        int currOverlap = 0, maxOverlap = 0;
        
        while(i < n && j < n) {
            if(start[i] <= end[j]) {
                currOverlap++;
                maxOverlap = max(maxOverlap, currOverlap);
                i++;
            } else {
                currOverlap--;
                j++;
            }
        }
        
        return maxOverlap;
    }
};
