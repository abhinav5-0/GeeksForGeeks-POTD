class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node* slow = head;
        Node* fast = head;

        // Detect loop using Floyd's Cycle Detection Algorithm.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected, find the start of the loop.
                Node* start = head;
                if (slow == head) {
                    // Special case when the loop starts at the head.
                    while (fast->next != head) {
                        fast = fast->next;
                    }
                } else {
                    while (start->next != slow->next) {
                        start = start->next;
                        slow = slow->next;
                    }
                }
                // Remove the loop by setting the next of the last node to NULL.
                slow->next = NULL;
                return;
            }
        }
    }
};
