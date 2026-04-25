class Solution:
    def reducePairs(self, arr):
        st = []
        
        for x in arr:
            while st and st[-1] * x < 0:
                if abs(st[-1]) > abs(x):
                    x = st.pop()
                elif abs(st[-1]) < abs(x):
                    st.pop()
                else:
                    st.pop()
                    x = 0
                    break
            if x != 0:
                st.append(x)
        
        return st
