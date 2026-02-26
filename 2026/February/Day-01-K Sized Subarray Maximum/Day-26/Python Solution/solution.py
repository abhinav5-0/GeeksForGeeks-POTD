class Solution:
    def areIsomorphic(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        
        map1 = {}
        map2 = {}
        
        for c1, c2 in zip(s1, s2):
            if c1 not in map1 and c2 not in map2:
                map1[c1] = c2
                map2[c2] = c1
            elif map1.get(c1) != c2:
                return False
        
        return True
