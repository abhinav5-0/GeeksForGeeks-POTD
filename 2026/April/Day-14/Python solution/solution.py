class Solution:
    def removeSpaces(self, s: str) -> str:
        result = ""
        for c in s:
            if c != ' ':
                result += c
        return result
