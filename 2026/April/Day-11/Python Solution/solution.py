class Solution:
    def countIncreasing(self, arr):
        count = 0
        length = 1

        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                length += 1
            else:
                count += (length * (length - 1)) // 2
                length = 1

        count += (length * (length - 1)) // 2
        return count
