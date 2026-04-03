class Solution:
    def diagView(self, mat):
        n = len(mat)
        res = []

        # First row
        for col in range(n):
            i, j = 0, col
            while i < n and j >= 0:
                res.append(mat[i][j])
                i += 1
                j -= 1

        # Last column
        for row in range(1, n):
            i, j = row, n - 1
            while i < n and j >= 0:
                res.append(mat[i][j])
                i += 1
                j -= 1

        return res
