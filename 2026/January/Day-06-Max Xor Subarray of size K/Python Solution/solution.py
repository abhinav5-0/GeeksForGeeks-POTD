class Solution:
    def maxSubarrayXOR(self, arr, k):
        xr = 0

        # XOR of first window
        for i in range(k):
            xr ^= arr[i]

        ans = xr

        # Sliding window
        for i in range(k, len(arr)):
            xr ^= arr[i - k]  # remove left
            xr ^= arr[i]      # add right
            ans = max(ans, xr)

        return ans
