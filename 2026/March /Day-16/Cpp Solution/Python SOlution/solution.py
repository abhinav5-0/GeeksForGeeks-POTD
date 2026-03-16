class Solution:
    
    def dfs(self, root, k, path):
        if not root:
            return
        
        path.append(root.data)
        
        s = 0
        for i in range(len(path)-1, -1, -1):
            s += path[i]
            if s == k:
                self.count += 1
        
        self.dfs(root.left, k, path)
        self.dfs(root.right, k, path)
        
        path.pop()
    
    def sumK(self, root, k):
        self.count = 0
        path = []
        
        self.dfs(root, k, path)
        
        return self.count
