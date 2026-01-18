class Solution:
    def nextFreqGreater(self, arr):
        from collections import Counter

        n = len(arr)
        freq = Counter(arr)
        ans = [-1] * n
        stack = []  # stores indices

        for i in range(n - 1, -1, -1):
            while stack and freq[arr[stack[-1]]] <= freq[arr[i]]:
                stack.pop()

            if stack:
                ans[i] = arr[stack[-1]]

            stack.append(i)

        return ans
