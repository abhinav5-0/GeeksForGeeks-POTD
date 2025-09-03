class Solution {
  public:
    Node *reverse(Node *head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        Node* temp = nullptr;
        
        // Traverse and swap next & prev for each node
        while (curr) {
            // Swap
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            
            // Move to the "next" node (which is actually prev after swapping)
            curr = curr->prev;
        }
        
        // After the loop, temp will point to the new head's previous node
        if (temp) head = temp->prev;
        
        return head;
    }
};
