class Solution:
    def largestBst(self, root):
        self.max_size = 0

        def solve(node):
            if not node:
                return (float('inf'), float('-inf'), 0, True)

            left = solve(node.left)
            right = solve(node.right)

            if left[3] and right[3] and left[1] < node.data < right[0]:
                size = left[2] + right[2] + 1
                self.max_size = max(self.max_size, size)

                return (
                    min(node.data, left[0]),
                    max(node.data, right[1]),
                    size,
                    True
                )

            return (float('-inf'), float('inf'),
                    max(left[2], right[2]), False)

        solve(root)
        return self.max_size
