class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if (head1 != nullptr) {
            tail->next = head1;
        } else if (head2 != nullptr) {
            tail->next = head2;
        }

        Node* mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
    }
};
