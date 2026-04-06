import heapq

class Node:
    def __init__(self, freq):
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


class Solution:
    def huffmanCodes(self, s, f):
        heap = []
        
        # Create leaf nodes
        for freq in f:
            heapq.heappush(heap, Node(freq))
        
        # Build tree
        while len(heap) > 1:
            left = heapq.heappop(heap)
            right = heapq.heappop(heap)
            
            new_node = Node(left.freq + right.freq)
            new_node.left = left
            new_node.right = right
            
            heapq.heappush(heap, new_node)
        
        root = heap[0]
        result = []
        
        self.generate(root, "", result)
        return result
    
    def generate(self, root, code, result):
        if root is None:
            return
        
        if root.left is None and root.right is None:
            result.append(code)
        
        self.generate(root.left, code + "0", result)
        self.generate(root.right, code + "1", result)
