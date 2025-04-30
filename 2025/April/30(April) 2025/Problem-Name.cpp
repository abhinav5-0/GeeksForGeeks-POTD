class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node *slow = head, *fast = head;

        // Step 1: Detect loop using Floyd's algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                // Step 2: Count the number of nodes in the loop
                int count = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }

        // No loop
        return 0;
    }
};
