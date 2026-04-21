class Solution:
    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def pour(self, frm, to, d):
        fromJug = frm
        toJug = 0
        steps = 1

        while fromJug != d and toJug != d:
            temp = min(fromJug, to - toJug)

            toJug += temp
            fromJug -= temp
            steps += 1

            if fromJug == d or toJug == d:
                break

            if fromJug == 0:
                fromJug = frm
                steps += 1

            if toJug == to:
                toJug = 0
                steps += 1

        return steps

    def minSteps(self, m, n, d):
        if d > max(m, n):
            return -1
        if d % self.gcd(m, n) != 0:
            return -1

        return min(self.pour(m, n, d), self.pour(n, m, d))
