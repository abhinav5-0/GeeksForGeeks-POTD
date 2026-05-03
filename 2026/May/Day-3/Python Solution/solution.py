class Solution:
    def sortBySetBitCount(self, arr):
        # Python sort is stable by default
        arr.sort(key=lambda x: bin(x).count('1'), reverse=True)
        return arr
