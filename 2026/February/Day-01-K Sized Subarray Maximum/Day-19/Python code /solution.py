class Solution:
    def missinRange(self, arr, low, high):
        s = set(arr)
        result = []
        
        for num in range(low, high + 1):
            if num not in s:
                result.append(num)
        
        return result
