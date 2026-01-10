class Solution:
    def atMost(self, s, k):
        if k < 0:
            return 0

        freq = [0] * 26
        left = distinct = 0
        ans = 0

        for right in range(len(s)):
            if freq[ord(s[right]) - ord('a')] == 0:
                distinct += 1
            freq[ord(s[right]) - ord('a')] += 1

            while distinct > k:
                freq[ord(s[left]) - ord('a')] -= 1
                if freq[ord(s[left]) - ord('a')] == 0:
                    distinct -= 1
                left += 1

            ans += (right - left + 1)

        return ans

    def countSubstr(self, s, k):
        return self.atMost(s, k) - self.atMost(s, k - 1)
