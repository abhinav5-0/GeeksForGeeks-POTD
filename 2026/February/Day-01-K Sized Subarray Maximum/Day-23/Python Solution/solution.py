class Solution:
    def findUnion(self, a, b):
        # Using set to remove duplicates
        result = set(a) | set(b)
        
        # Return sorted list (as driver prints in sorted order)
        return sorted(result)
