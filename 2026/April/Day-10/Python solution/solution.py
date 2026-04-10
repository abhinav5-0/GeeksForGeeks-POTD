class Solution:
    def find3Numbers(self, arr):
        n = len(arr)
        if n < 3:
            return []

        smaller = [-1] * n
        greater = [-1] * n

        # Step 1: smaller[]
        min_idx = 0
        for i in range(1, n):
            if arr[i] <= arr[min_idx]:
                min_idx = i
            else:
                smaller[i] = min_idx

        # Step 2: greater[]
        max_idx = n - 1
        for i in range(n - 2, -1, -1):
            if arr[i] >= arr[max_idx]:
                max_idx = i
            else:
                greater[i] = max_idx

        # Step 3: find answer
        for i in range(n):
            if smaller[i] != -1 and greater[i] != -1:
                return [arr[smaller[i]], arr[i], arr[greater[i]]]

        return []
