from collections import deque

class Solution:
    def maxOfSubarrays(self, arr, k):
        dq = deque()   # stores indices
        ans = []

        for i in range(len(arr)):

            # 1. Remove out-of-window indices
            if dq and dq[0] <= i - k:
                dq.popleft()

            # 2. Remove smaller elements
            while dq and arr[dq[-1]] <= arr[i]:
                dq.pop()

            # 3. Add current index
            dq.append(i)

            # 4. Window ready → add answer
            if i >= k - 1:
                ans.append(arr[dq[0]])

        return ans
