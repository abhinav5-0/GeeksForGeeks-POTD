class Solution:
    def maxSum(self, arr):
        n = len(arr)

        arrSum = sum(arr)
        currVal = sum(i * arr[i] for i in range(n))

        maxVal = currVal

        for i in range(1, n):
            currVal = currVal + arrSum - n * arr[n - i]
            maxVal = max(maxVal, currVal)

        return maxVal
