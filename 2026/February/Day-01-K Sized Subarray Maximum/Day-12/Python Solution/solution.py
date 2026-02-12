class Solution:
    def canAchieve(self, arr, k, w, target):
        n = len(arr)
        diff = [0] * (n + 1)

        water_used = 0
        curr_add = 0

        for i in range(n):
            curr_add += diff[i]
            current_height = arr[i] + curr_add

            if current_height < target:
                need = target - current_height
                water_used += need

                if water_used > k:
                    return False

                curr_add += need
                if i + w < n:
                    diff[i + w] -= need

        return True

    def maxMinHeight(self, arr, k, w):
        low = min(arr)
        high = low + k
        ans = low

        while low <= high:
            mid = (low + high) // 2

            if self.canAchieve(arr, k, w, mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans
