class Solution:
    def maxProfit(self, arr, k):
        hold = -arr[0]
        cash = 0

        for i in range(1, len(arr)):
            hold = max(hold, cash - arr[i])
            cash = max(cash, hold + arr[i] - k)

        return cash
