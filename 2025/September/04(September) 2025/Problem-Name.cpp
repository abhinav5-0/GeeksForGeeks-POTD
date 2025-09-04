class Solution {
  public:
    // Helper to reverse 'k' nodes starting from 'head'
    Node* reverseK(Node* head, int k) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // prev = new head after reversal
        // head = old head, now becomes tail of this group
        head->next = curr;  // temporarily link, will be fixed later
        return prev;
    }

    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prevGroupEnd = dummy;
        Node* curr = head;

        while (curr) {
            // Count k nodes ahead
            Node* temp = curr;
            int count = 0;
            while (temp && count < k) {
                temp = temp->next;
                count++;
            }

            // If less than k, still reverse (per problem statement)
            if (count > 0) {
                Node* groupHead = curr;
                Node* prev = NULL;
                Node* next = NULL;
                int c = 0;

                // Reverse 'count' nodes (even if less than k)
                while (curr && c < count) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    c++;
                }

                // Connect previous group end with new head
                prevGroupEnd->next = prev;
                prevGroupEnd = groupHead; // old head becomes end
            }
        }

        return dummy->next;
    }
};
