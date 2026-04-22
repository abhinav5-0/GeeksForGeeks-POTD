class Solution:
    def findMean(self, arr, queries):
        n = len(arr)
        
        # Prefix sum array
        prefix = [0] * n
        prefix[0] = arr[0]
        
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + arr[i]
        
        result = []
        
        for l, r in queries:
            sum_val = prefix[r] - (prefix[l - 1] if l > 0 else 0)
            length = r - l + 1
            
            result.append(sum_val // length)  # floor
        
        return result
