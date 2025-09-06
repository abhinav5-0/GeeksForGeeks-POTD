class Solution {
public:
    int lengthOfLoop(Node *head) {
        if (!head) return 0;
        
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd's algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // Loop detected
                // Step 2: Count loop length
                int count = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }

        return 0; // No loop
    }
};
