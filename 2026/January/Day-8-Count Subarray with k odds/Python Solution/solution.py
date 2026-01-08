class Solution:
    def countSubarrays(self, arr, k):
        freq = {0: 1}
        prefix_sum = 0
        count = 0
        
        for num in arr:
            prefix_sum += num % 2  # odd -> 1
            
            count += freq.get(prefix_sum - k, 0)
            
            freq[prefix_sum] = freq.get(prefix_sum, 0) + 1
        
        return count
