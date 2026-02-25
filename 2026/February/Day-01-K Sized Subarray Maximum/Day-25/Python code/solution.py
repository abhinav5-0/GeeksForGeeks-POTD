class Solution:
    def longestSubarray(self, arr, k):
        prefix = 0
        max_len = 0
        first_index = {}
        
        for i in range(len(arr)):
            if arr[i] > k:
                prefix += 1
            else:
                prefix -= 1
            
            if prefix > 0:
                max_len = i + 1
            
            if prefix not in first_index:
                first_index[prefix] = i
            
            if (prefix - 1) in first_index:
                max_len = max(max_len, i - first_index[prefix - 1])
        
        return max_len
