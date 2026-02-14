class Solution:
    def isPossible(self, arr, k, maxTime):
        curr_sum = 0
        painters = 1

        for num in arr:
            if curr_sum + num <= maxTime:
                curr_sum += num
            else:
                painters += 1
                curr_sum = num
                if painters > k:
                    return False
        return True

    def minTime(self, arr, k):
        low = max(arr)
        high = sum(arr)
        ans = high

        while low <= high:
            mid = (low + high) // 2

            if self.isPossible(arr, k, mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans
