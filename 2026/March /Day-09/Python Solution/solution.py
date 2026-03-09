class Solution:
    def largestSwap(self, s: str) -> str:
        last = [-1] * 10

        for i, ch in enumerate(s):
            last[int(ch)] = i

        s = list(s)

        for i in range(len(s)):
            for d in range(9, int(s[i]), -1):
                if last[d] > i:
                    s[i], s[last[d]] = s[last[d]], s[i]
                    return "".join(s)

        return "".join(s)
