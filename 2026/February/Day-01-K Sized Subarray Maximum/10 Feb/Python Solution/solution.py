class Solution:
    def canEat(self, arr, k, s):
        hours = 0
        for bananas in arr:
            hours += (bananas + s - 1) // s   # ceil division
        return hours <= k

    def kokoEat(self, arr, k):
        low, high = 1, max(arr)
        ans = high

        while low <= high:
            mid = (low + high) // 2

            if self.canEat(arr, k, mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans
