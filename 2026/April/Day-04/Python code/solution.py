class Solution:
    def graycode(self, n):
        res = ["0", "1"]

        for i in range(2, n + 1):
            temp = []

            # prefix 0
            for s in res:
                temp.append("0" + s)

            # prefix 1 (reverse order)
            for s in reversed(res):
                temp.append("1" + s)

            res = temp

        return res
