class Solution:
    def maxSubarrayXOR(self, arr, k):
        n = len(arr)
        xr = 0

        # XOR of first window
        for i in range(k):
            xr ^= arr[i]

        ans = xr

        # Sliding window
        for i in range(k, n):
            xr ^= arr[i - k]   # remove left element
            xr ^= arr[i]       # add right element
            ans = max(ans, xr)

        return ans
