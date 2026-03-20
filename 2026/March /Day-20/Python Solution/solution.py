class Solution:
    def findPreSuc(self, root, key):
        pre, suc = None, None

        while root:
            if root.data < key:
                pre = root
                root = root.right
            else:
                suc = root
                root = root.left

        return [
            pre.data if pre else -1,
            suc.data if suc else -1
        ]
