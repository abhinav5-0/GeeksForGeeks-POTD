class Solution:
    def maxSubarraySum(self, arr, k):
        n = len(arr)
        
        # Sum of first k elements
        window_sum = sum(arr[:k])
        max_sum = window_sum

        # Sliding window
        for i in range(k, n):
            window_sum = window_sum + arr[i] - arr[i - k]
            max_sum = max(max_sum, window_sum)

        return max_sum
