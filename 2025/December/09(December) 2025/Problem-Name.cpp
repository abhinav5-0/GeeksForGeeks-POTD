class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        
        for (int i = 0; i < arr.size(); i++) {
            int x = abs(arr[i]);
            
            // If already visited, it's a duplicate
            if (arr[x - 1] < 0) {
                ans.push_back(x);
            } else {
                arr[x - 1] = -arr[x - 1];
            }
        }
        
        return ans;
    }
};
