class Solution:
    def countSubset(self, arr, k):
        n = len(arr)
        mid = n // 2

        left = arr[:mid]
        right = arr[mid:]

        from collections import defaultdict
        freq = defaultdict(int)

        # Left half subset sums
        for mask in range(1 << len(left)):
            s = 0
            for i in range(len(left)):
                if mask & (1 << i):
                    s += left[i]
            freq[s] += 1

        ans = 0

        # Right half subset sums
        for mask in range(1 << len(right)):
            s = 0
            for i in range(len(right)):
                if mask & (1 << i):
                    s += right[i]
            ans += freq[k - s]

        return ans
