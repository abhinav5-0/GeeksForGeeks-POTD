from collections import deque

class Solution:
    def minTime(self, root, target):
        parent = {}
        target_node = None

        # Step 1: Build parent map
        def build_parent(root):
            nonlocal target_node
            q = deque([root])

            while q:
                node = q.popleft()

                if node.data == target:
                    target_node = node

                if node.left:
                    parent[node.left] = node
                    q.append(node.left)

                if node.right:
                    parent[node.right] = node
                    q.append(node.right)

        build_parent(root)

        # Step 2: BFS from target
        visited = set()
        q = deque([target_node])
        visited.add(target_node)

        time = 0

        while q:
            size = len(q)
            burned = False

            for _ in range(size):
                node = q.popleft()

                for nei in (node.left, node.right, parent.get(node)):
                    if nei and nei not in visited:
                        burned = True
                        visited.add(nei)
                        q.append(nei)

            if burned:
                time += 1

        return time
