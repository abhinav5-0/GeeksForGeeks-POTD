class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* prev = NULL;  // Previous node
        Node* curr = head;  // Current node
        Node* next = NULL;  // Next node
        
        while (curr != NULL) {
            // Store the next node
            next = curr->next;
            // Reverse the current node's pointer
            curr->next = prev;
            // Move pointers one step forward
            prev = curr;
            curr = next;
        }
        
        // New head of the reversed list
        return prev;
    }
};
