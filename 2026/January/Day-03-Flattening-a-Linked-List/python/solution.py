class Solution:
    
    # Merge two sorted bottom-linked lists
    def merge(self, a, b):
        if not a:
            return b
        if not b:
            return a

        if a.data < b.data:
            result = a
            result.bottom = self.merge(a.bottom, b)
        else:
            result = b
            result.bottom = self.merge(a, b.bottom)

        result.next = None  # important
        return result

    def flatten(self, root):
        # Base case
        if not root or not root.next:
            return root

        # Flatten the right list
        root.next = self.flatten(root.next)

        # Merge current list with flattened list
        root = self.merge(root, root.next)

        return root
