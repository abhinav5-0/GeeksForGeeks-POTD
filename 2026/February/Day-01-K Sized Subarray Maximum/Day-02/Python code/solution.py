class Solution:
    def kadane_max(self, arr):
        curr = best = arr[0]
        for x in arr[1:]:
            curr = max(x, curr + x)
            best = max(best, curr)
        return best

    def kadane_min(self, arr):
        curr = best = arr[0]
        for x in arr[1:]:
            curr = min(x, curr + x)
            best = min(best, curr)
        return best

    def maxCircularSum(self, arr):
        normal_max = self.kadane_max(arr)

        # All elements are negative
        if normal_max < 0:
            return normal_max

        total_sum = sum(arr)
        min_subarray = self.kadane_min(arr)

        return max(normal_max, total_sum - min_subarray)
