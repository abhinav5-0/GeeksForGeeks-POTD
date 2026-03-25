from collections import deque

class Solution:
    def minHeightRoots(self, V, edges):
        if V == 1:
            return [0]

        adj = [[] for _ in range(V)]
        degree = [0] * V

        # Build graph
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            degree[u] += 1
            degree[v] += 1

        q = deque()

        # Push all leaf nodes
        for i in range(V):
            if degree[i] == 1:
                q.append(i)

        remaining = V

        # Remove leaves level by level
        while remaining > 2:
            size = len(q)
            remaining -= size

            for _ in range(size):
                node = q.popleft()
                for neighbor in adj[node]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        q.append(neighbor)

        return list(q)
