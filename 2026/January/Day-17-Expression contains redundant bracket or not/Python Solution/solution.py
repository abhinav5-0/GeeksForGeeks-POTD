class Solution:
    def checkRedundancy(self, s: str) -> bool:
        stack = []

        for ch in s:
            if ch == ')':
                has_operator = False

                while stack and stack[-1] != '(':
                    top = stack.pop()
                    if top in "+-*/":
                        has_operator = True

                # pop '('
                if stack:
                    stack.pop()

                # redundant bracket
                if not has_operator:
                    return True
            else:
                stack.append(ch)

        return False
