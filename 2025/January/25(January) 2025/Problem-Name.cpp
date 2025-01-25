class Solution {
public:
    Node* findFirstNode(Node* head) {
        if (!head || !head->next) return NULL;

        Node* slow = head;
        Node* fast = head;

        // Detect loop using Floyd's Cycle Detection
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected
                break;
            }
        }

        // If no loop exists
        if (!fast || !fast->next) return NULL;

        // Find the first node of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // First node of the loop
    }
};
