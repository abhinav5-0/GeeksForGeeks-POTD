class Solution:
    def findClosestPair(self, arr1, arr2, x):
        n = len(arr1)
        m = len(arr2)
        
        left = 0
        right = m - 1
        
        min_diff = float('inf')
        result = [0, 0]
        
        while left < n and right >= 0:
            total = arr1[left] + arr2[right]
            diff = abs(total - x)
            
            if diff < min_diff:
                min_diff = diff
                result[0] = arr1[left]
                result[1] = arr2[right]
            
            if total > x:
                right -= 1
            else:
                left += 1
        
        return result
