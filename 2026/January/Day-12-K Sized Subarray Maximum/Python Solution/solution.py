from collections import deque

class Solution:
    def maxOfSubarrays(self, arr, k):
        result = []
        dq = deque()

        for i in range(len(arr)):
            # Remove elements out of window
            if dq and dq[0] <= i - k:
                dq.popleft()

            # Remove smaller elements
            while dq and arr[dq[-1]] <= arr[i]:
                dq.pop()

            dq.append(i)

            # Store maximum of window
            if i >= k - 1:
                result.append(arr[dq[0]])

        return result
