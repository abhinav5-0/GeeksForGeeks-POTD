class Solution:
    def totalWays(self, arr, target):
        total_sum = sum(arr)

        if (total_sum + target) % 2 != 0 or abs(target) > total_sum:
            return 0

        P = (total_sum + target) // 2

        dp = [0] * (P + 1)
        dp[0] = 1

        for num in arr:
            for j in range(P, num - 1, -1):
                dp[j] += dp[j - num]

        return dp[P]
