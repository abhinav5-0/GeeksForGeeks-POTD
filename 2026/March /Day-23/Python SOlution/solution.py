class Solution:
    def longestCycle(self, V, edges):
        next_node = [-1] * V

        # Build mapping
        for u, v in edges:
            next_node[u] = v

        vis = [0] * V
        ans = -1

        for i in range(V):
            if vis[i]:
                continue

            step = {}
            node = i
            cnt = 0

            while node != -1 and not vis[node]:
                vis[node] = 1
                step[node] = cnt
                cnt += 1
                node = next_node[node]

                if node != -1 and node in step:
                    ans = max(ans, cnt - step[node])
                    break

        return ans
