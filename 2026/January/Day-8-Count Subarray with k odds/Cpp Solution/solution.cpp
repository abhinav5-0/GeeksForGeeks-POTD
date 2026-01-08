class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // prefix sum 0 occurs once
        
        int prefixSum = 0, count = 0;
        
        for (int num : arr) {
            prefixSum += (num % 2);   // odd -> 1, even -> 0
            
            if (freq.find(prefixSum - k) != freq.end()) {
                count += freq[prefixSum - k];
            }
            
            freq[prefixSum]++;
        }
        
        return count;
    }
};
