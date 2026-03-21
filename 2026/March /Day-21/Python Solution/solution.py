class Solution:
    def findPreSuc(self, root, key):
        pre, suc = -1, -1

        temp = root

        # Predecessor
        while temp:
            if key > temp.data:
                pre = temp.data
                temp = temp.right
            else:
                temp = temp.left

        temp = root

        # Successor
        while temp:
            if key < temp.data:
                suc = temp.data
                temp = temp.left
            else:
                temp = temp.right

        return [pre, suc]
