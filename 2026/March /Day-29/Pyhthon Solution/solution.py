class Solution:
    def countPartitions(self, arr, diff):
        totalSum = sum(arr)
        
        # Edge cases
        if totalSum < diff or (totalSum + diff) % 2 != 0:
            return 0
        
        target = (totalSum + diff) // 2
        
        dp = [0] * (target + 1)
        dp[0] = 1
        
        for num in arr:
            for j in range(target, num - 1, -1):
                dp[j] += dp[j - num]
        
        return dp[target]
