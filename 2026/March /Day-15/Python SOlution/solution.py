from collections import defaultdict, deque

class Solution:
    def verticalOrder(self, root):
        
        mp = defaultdict(list)
        q = deque([(root, 0)])
        
        while q:
            node, hd = q.popleft()
            
            mp[hd].append(node.data)
            
            if node.left:
                q.append((node.left, hd - 1))
                
            if node.right:
                q.append((node.right, hd + 1))
        
        result = []
        
        for key in sorted(mp.keys()):
            result.append(mp[key])
            
        return result
