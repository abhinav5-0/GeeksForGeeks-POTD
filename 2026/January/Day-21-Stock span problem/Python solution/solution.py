class Solution:
    def calculateSpan(self, arr):
        n = len(arr)
        span = [0] * n
        stack = []  # stores indices

        for i in range(n):
            # Pop while current price is higher or equal
            while stack and arr[stack[-1]] <= arr[i]:
                stack.pop()

            # If stack empty, span is i+1
            span[i] = i + 1 if not stack else i - stack[-1]

            # Push current index
            stack.append(i)

        return span
