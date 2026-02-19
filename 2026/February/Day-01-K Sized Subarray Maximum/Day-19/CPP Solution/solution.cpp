class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> result;
        
        for(int i = low; i <= high; i++) {
            if(s.find(i) == s.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
