class Solution:
    def canFormPalindrome(self, s: str) -> bool:
        freq = [0] * 26

        for c in s:
            freq[ord(c) - ord('a')] += 1

        odd_count = sum(1 for f in freq if f % 2 != 0)

        return odd_count <= 1
