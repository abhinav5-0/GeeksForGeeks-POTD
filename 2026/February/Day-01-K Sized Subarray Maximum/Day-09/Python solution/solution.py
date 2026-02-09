class Solution:
    def findKRotation(self, arr):
        min_index = 0

        for i in range(1, len(arr)):
            if arr[i] < arr[min_index]:
                min_index = i

        return min_index
