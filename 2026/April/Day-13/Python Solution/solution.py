class Solution:
    def nextPalindrome(self, num):
        n = len(num)
        
        # Step 1: check all 9s
        if all(d == 9 for d in num):
            return [1] + [0]*(n-1) + [1]
        
        res = num[:]
        
        # Step 2: mirror
        i, j = 0, n-1
        while i < j:
            res[j] = res[i]
            i += 1
            j -= 1
        
        # Step 3: check
        if res > num:
            return res
        
        # Step 4: increment middle
        carry = 1
        mid = n // 2
        
        if n % 2 == 1:
            res[mid] += carry
            carry = res[mid] // 10
            res[mid] %= 10
            i, j = mid-1, mid+1
        else:
            i, j = mid-1, mid
        
        # Step 5: propagate carry
        while i >= 0 and carry:
            res[i] += carry
            carry = res[i] // 10
            res[i] %= 10
            res[j] = res[i]
            i -= 1
            j += 1
        
        return res
