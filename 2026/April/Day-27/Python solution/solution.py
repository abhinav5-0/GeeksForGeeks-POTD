class Solution:
    def smallestSubstring(self, s: str) -> int:
        count = [0, 0, 0]
        left = 0
        ans = float('inf')

        for right in range(len(s)):
            count[int(s[right])] += 1

            while count[0] > 0 and count[1] > 0 and count[2] > 0:
                ans = min(ans, right - left + 1)
                count[int(s[left])] -= 1
                left += 1

        return -1 if ans == float('inf') else ans
