class Solution:
    def isMaxHeap(self, arr):
        n = len(arr)

        # Only check non-leaf nodes
        for i in range((n - 2) // 2 + 1):
            left = 2 * i + 1
            right = 2 * i + 2

            if left < n and arr[i] < arr[left]:
                return False
            if right < n and arr[i] < arr[right]:
                return False

        return True
