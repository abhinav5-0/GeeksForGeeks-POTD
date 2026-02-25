class Solution {
public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        
        unordered_map<int, int> firstIndex;
        int prefix = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > k)
                prefix += 1;
            else
                prefix -= 1;
            
            if(prefix > 0)
                maxLen = i + 1;
            
            if(firstIndex.find(prefix) == firstIndex.end())
                firstIndex[prefix] = i;
            
            if(firstIndex.find(prefix - 1) != firstIndex.end())
                maxLen = max(maxLen, i - firstIndex[prefix - 1]);
        }
        
        return maxLen;
    }
};
