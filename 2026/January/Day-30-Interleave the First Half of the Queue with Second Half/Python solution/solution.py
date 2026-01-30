from collections import deque

class Solution:
    def rearrangeQueue(self, q):
        n = len(q)
        half = n // 2

        firstHalf = deque()

        # Step 1
        for _ in range(half):
            firstHalf.append(q.popleft())

        # Step 2
        while firstHalf:
            q.append(firstHalf.popleft())
            q.append(q.popleft())
