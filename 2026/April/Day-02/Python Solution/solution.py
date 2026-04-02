class Solution:
    def countWays(self, n, k):
        if n == 1:
            return k
        if n == 2:
            return k * k

        same = k
        diff = k * (k - 1)

        for _ in range(3, n + 1):
            new_same = diff
            new_diff = (same + diff) * (k - 1)

            same = new_same
            diff = new_diff

        return same + diff
