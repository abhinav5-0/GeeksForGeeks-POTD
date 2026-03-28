class Solution:
    def articulationPoints(self, V, edges):
        adj = [[] for _ in range(V)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        vis = [0] * V
        tin = [-1] * V
        low = [-1] * V
        mark = [0] * V
        timer = 0

        def dfs(node, parent):
            nonlocal timer
            vis[node] = 1
            tin[node] = low[node] = timer
            timer += 1
            child = 0

            for it in adj[node]:
                if it == parent:
                    continue

                if not vis[it]:
                    dfs(it, node)
                    low[node] = min(low[node], low[it])

                    if low[it] >= tin[node] and parent != -1:
                        mark[node] = 1
                    child += 1
                else:
                    low[node] = min(low[node], tin[it])

            if parent == -1 and child > 1:
                mark[node] = 1

        for i in range(V):
            if not vis[i]:
                dfs(i, -1)

        ans = [i for i in range(V) if mark[i]]
        return ans if ans else [-1]
