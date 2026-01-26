class Solution:
    def solve(self, idx, arr, ans):
        if idx == len(arr):
            ans.append(arr[:])
            return

        for i in range(idx, len(arr)):
            arr[idx], arr[i] = arr[i], arr[idx]
            self.solve(idx + 1, arr, ans)
            arr[idx], arr[i] = arr[i], arr[idx]  # backtrack

    def permuteDist(self, arr):
        ans = []
        self.solve(0, arr, ans)
        return ans
