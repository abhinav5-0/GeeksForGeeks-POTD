class Solution:
    def minMen(self, arr):
        n = len(arr)
        intervals = []

        # Create intervals
        for i in range(n):
            if arr[i] != -1:
                start = max(0, i - arr[i])
                end = min(n - 1, i + arr[i])
                intervals.append((start, end))

        # Sort intervals by start
        intervals.sort()

        cnt = 0
        i = 0
        covered = 0

        # Greedy covering
        while covered < n:
            farthest = covered

            while i < len(intervals) and intervals[i][0] <= covered:
                farthest = max(farthest, intervals[i][1] + 1)
                i += 1

            if farthest == covered:
                return -1

            cnt += 1
            covered = farthest

        return cnt
