class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        // Dummy nodes for 0, 1, 2 lists
        Node* zeroD = new Node(-1);
        Node* oneD  = new Node(-1);
        Node* twoD  = new Node(-1);

        // Tails for each list
        Node* zero = zeroD;
        Node* one  = oneD;
        Node* two  = twoD;

        // Traverse original list
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            }
            else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            }
            else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect the three lists
        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        // New head
        head = zeroD->next;

        // Cleanup dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
    }
};
