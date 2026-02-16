class Solution:
    def canAttend(self, arr):
        # Sort based on starting time
        arr.sort()
        
        for i in range(1, len(arr)):
            if arr[i][0] < arr[i-1][1]:
                return False  # Overlapping
        
        return True  # No overlapping
