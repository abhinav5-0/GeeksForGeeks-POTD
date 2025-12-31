class Solution {
  public:
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle of the linked list
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        Node *prev = nullptr;
        Node *curr = slow->next;
        while (curr) {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare first half and second half
        Node *first = head;
        Node *second = prev;
        while (second) {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
