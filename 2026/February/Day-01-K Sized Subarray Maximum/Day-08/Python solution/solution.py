class Solution:
    def maxProduct(self, arr):
        maxEndingHere = arr[0]
        minEndingHere = arr[0]
        ans = arr[0]

        for i in range(1, len(arr)):
            if arr[i] < 0:
                maxEndingHere, minEndingHere = minEndingHere, maxEndingHere

            maxEndingHere = max(arr[i], maxEndingHere * arr[i])
            minEndingHere = min(arr[i], minEndingHere * arr[i])

            ans = max(ans, maxEndingHere)

        return ans
