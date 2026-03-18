class Solution:
    def __init__(self):
        self.moves = 0

    def dfs(self, root):
        if not root:
            return 0

        left = self.dfs(root.left)
        right = self.dfs(root.right)

        self.moves += abs(left) + abs(right)

        return root.data + left + right - 1

    def distCandy(self, root):
        self.moves = 0
        self.dfs(root)
        return self.moves
