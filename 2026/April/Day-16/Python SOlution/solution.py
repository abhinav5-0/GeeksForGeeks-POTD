class Solution:
    def myAtoi(self, s: str) -> int:
        i, n = 0, len(s)
        
        # 1. Skip whitespaces
        while i < n and s[i] == ' ':
            i += 1
        
        # 2. Handle sign
        sign = 1
        if i < n and (s[i] == '+' or s[i] == '-'):
            if s[i] == '-':
                sign = -1
            i += 1
        
        # 3. Convert digits
        result = 0
        while i < n and s[i].isdigit():
            digit = int(s[i])
            
            # 4. Check overflow
            if result > (2**31 - 1 - digit) // 10:
                return 2**31 - 1 if sign == 1 else -2**31
            
            result = result * 10 + digit
            i += 1
        
        return sign * result
