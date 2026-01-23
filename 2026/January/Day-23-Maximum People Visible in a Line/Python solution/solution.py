class Solution:
    def maxPeople(self, arr):
        n = len(arr)
        left = [0] * n
        right = [0] * n
        stack = []

        # Left side
        for i in range(n):
            while stack and arr[stack[-1]] < arr[i]:
                left[i] += 1
                stack.pop()
            if stack:
                left[i] += 1
            stack.append(i)

        stack.clear()

        # Right side
        for i in range(n - 1, -1, -1):
            while stack and arr[stack[-1]] < arr[i]:
                right[i] += 1
                stack.pop()
            if stack:
                right[i] += 1
            stack.append(i)

        ans = 0
        for i in range(n):
            ans = max(ans, left[i] + right[i] + 1)

        return ans
