class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        
        // Pair: {value, original index}
        vector<pair<int, int>> temp(n);
        for(int i = 0; i < n; i++) {
            temp[i] = {arr[i], i};
        }
        
        // Sort based on values
        sort(temp.begin(), temp.end());
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for(int i = 0; i < n; i++) {
            // already visited or already in correct position
            if(visited[i] || temp[i].second == i)
                continue;
            
            int cycle_size = 0;
            int j = i;
            
            // find cycle
            while(!visited[j]) {
                visited[j] = true;
                j = temp[j].second;
                cycle_size++;
            }
            
            if(cycle_size > 1)
                swaps += (cycle_size - 1);
        }
        
        return swaps;
    }
};
