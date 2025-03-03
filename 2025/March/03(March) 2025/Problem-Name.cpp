class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, right = 0, maxLen = 0, startIdx = 0;
        multiset<int> window;
        
        while (right < n) {
            window.insert(arr[right]);
            
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left]));
                left++;
            }
            
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIdx = left;
            }
            
            right++;
        }
        
        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
    }
};
