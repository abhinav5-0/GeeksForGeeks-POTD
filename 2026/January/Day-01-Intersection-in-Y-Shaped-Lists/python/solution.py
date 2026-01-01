class Solution:
    def intersectPoint(self, head1, head2):
        p1 = head1
        p2 = head2

        # Traverse until both pointers meet
        while p1 != p2:
            p1 = head2 if p1 is None else p1.next
            p2 = head1 if p2 is None else p2.next

        # Intersection node
        return p1
