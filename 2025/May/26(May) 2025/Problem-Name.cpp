class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // Case 1: Empty list
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        // Case 2: Insert before head (new minimum) or in correct sorted position
        while (true) {
            // Case a: Insert between two nodes
            if (curr->data <= data && curr->next->data >= data) {
                break;
            }

            // Case b: Insert at the turning point (max to min)
            if (curr->data > curr->next->data) {
                if (data >= curr->data || data <= curr->next->data) {
                    break;
                }
            }

            curr = curr->next;

            // If we complete one full circle
            if (curr == head) break;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        // If the new node is the new head (new min), return it
        if (data < head->data) return newNode;
        return head;
    }
};
