class Solution:
    def findWays(self, n: int) -> int:
        if n % 2 != 0:
            return 0

        k = n // 2
        dp = [0] * (k + 1)
        dp[0] = 1

        for i in range(1, k + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - j - 1]

        return dp[k]
