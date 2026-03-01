class Solution:
    def pushZerosToEnd(self, arr):
        n = len(arr)
        j = 0  # Position for next non-zero element
        
        for i in range(n):
            if arr[i] != 0:
                arr[i], arr[j] = arr[j], arr[i]
                j += 1
