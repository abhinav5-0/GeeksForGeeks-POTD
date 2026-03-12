class Solution:
    def kBitFlips(self, arr, k):
        n = len(arr)
        flip = [0]*n
        ans = 0
        curr = 0

        for i in range(n):
            if i >= k:
                curr ^= flip[i-k]

            if (arr[i] ^ curr) == 0:
                if i + k > n:
                    return -1

                ans += 1
                curr ^= 1
                flip[i] = 1

        return ans
