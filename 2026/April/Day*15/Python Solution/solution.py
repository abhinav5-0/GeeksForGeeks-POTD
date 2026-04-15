class Solution:
    def URLify(self, s: str) -> str:
        result = ""
        for c in s:
            if c == ' ':
                result += "%20"
            else:
                result += c
        return result
