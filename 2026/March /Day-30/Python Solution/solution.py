class Solution:
    def minCost(self, houses):
        n = len(houses)
        
        minDist = [float('inf')] * n
        visited = [False] * n
        
        minDist[0] = 0
        cost = 0
        
        for _ in range(n):
            u = -1
            
            for i in range(n):
                if not visited[i] and (u == -1 or minDist[i] < minDist[u]):
                    u = i
            
            visited[u] = True
            cost += minDist[u]
            
            for v in range(n):
                if not visited[v]:
                    dist = abs(houses[u][0] - houses[v][0]) + \
                           abs(houses[u][1] - houses[v][1])
                    
                    minDist[v] = min(minDist[v], dist)
        
        return cost
