from collections import deque

def canFinish(n, prerequisites):
    adj = [[] for _ in range(n)]
    indegree = [0] * n
    
    # Build graph
    for x, y in prerequisites:
        adj[y].append(x)
        indegree[x] += 1
    
    q = deque()
    
    # Add nodes with 0 indegree
    for i in range(n):
        if indegree[i] == 0:
            q.append(i)
    
    count = 0
    
    while q:
        node = q.popleft()
        count += 1
        
        for neigh in adj[node]:
            indegree[neigh] -= 1
            if indegree[neigh] == 0:
                q.append(neigh)
    
    return count == n
