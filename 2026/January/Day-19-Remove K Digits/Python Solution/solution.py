class Solution:
    def removeKdig(self, s: str, k: int) -> str:
        stack = []

        for c in s:
            while stack and k > 0 and stack[-1] > c:
                stack.pop()
                k -= 1
            stack.append(c)

        # Remove remaining digits from end
        while k > 0:
            stack.pop()
            k -= 1

        # Convert to string and strip leading zeros
        res = ''.join(stack).lstrip('0')
        return res if res else "0"
