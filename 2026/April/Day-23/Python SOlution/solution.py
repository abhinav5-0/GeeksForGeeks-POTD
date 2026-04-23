class Solution:
    def canSplit(self, arr):
        total = sum(arr)

        if total % 2 != 0:
            return False

        prefix = 0
        for x in arr:
            prefix += x
            if prefix == total // 2:
                return True

        return False
