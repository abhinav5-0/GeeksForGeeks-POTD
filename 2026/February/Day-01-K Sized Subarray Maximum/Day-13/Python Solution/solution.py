class Solution:
    
    def digitSum(self, x):
        return sum(int(d) for d in str(x))
    
    def getCount(self, n, d):
        low, high = 1, n
        ans = -1
        
        while low <= high:
            mid = (low + high) // 2
            
            if mid - self.digitSum(mid) >= d:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        if ans == -1:
            return 0
        
        return n - ans + 1
