class Solution:
    def pythagoreanTriplet(self, arr):
        n = len(arr)

        # Square all elements
        arr = [x*x for x in arr]

        # Sort array
        arr.sort()

        # Fix c^2
        for i in range(n-1, 1, -1):
            l = 0
            r = i - 1

            while l < r:
                if arr[l] + arr[r] == arr[i]:
                    return True
                elif arr[l] + arr[r] < arr[i]:
                    l += 1
                else:
                    r -= 1

        return False
