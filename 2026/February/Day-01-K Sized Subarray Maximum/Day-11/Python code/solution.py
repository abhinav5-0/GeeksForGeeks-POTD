class Solution:
    def minCost(self, heights, cost):
        n = len(heights)
        
        arr = list(zip(heights, cost))
        arr.sort()
        
        total_cost = sum(c for _, c in arr)
        
        # Find weighted median
        curr = 0
        target = 0
        
        for h, c in arr:
            curr += c
            if curr >= (total_cost + 1) // 2:
                target = h
                break
        
        # Calculate minimum cost
        answer = 0
        for h, c in zip(heights, cost):
            answer += abs(h - target) * c
        
        return answer
