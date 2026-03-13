class Solution:
    
    def isValid(self, s):
        if len(s) > 1 and s[0] == '0':
            return False
        num = int(s)
        return 0 <= num <= 255

    def generateIp(self, s):
        res = []
        n = len(s)

        for i in range(1, 4):
            for j in range(i+1, i+4):
                for k in range(j+1, j+4):

                    if k >= n:
                        continue

                    a = s[:i]
                    b = s[i:j]
                    c = s[j:k]
                    d = s[k:]

                    if len(d) > 3:
                        continue

                    if self.isValid(a) and self.isValid(b) and self.isValid(c) and self.isValid(d):
                        res.append(a + "." + b + "." + c + "." + d)

        return res
