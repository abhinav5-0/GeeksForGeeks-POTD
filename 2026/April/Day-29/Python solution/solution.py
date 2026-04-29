class Solution:
    def minSwaps(self, arr):
        n = len(arr)
        
        temp = [(arr[i], i) for i in range(n)]
        temp.sort()
        
        visited = [False] * n
        swaps = 0
        
        for i in range(n):
            if visited[i] or temp[i][1] == i:
                continue
            
            cycle_size = 0
            j = i
            
            while not visited[j]:
                visited[j] = True
                j = temp[j][1]
                cycle_size += 1
            
            if cycle_size > 1:
                swaps += (cycle_size - 1)
        
        return swaps
