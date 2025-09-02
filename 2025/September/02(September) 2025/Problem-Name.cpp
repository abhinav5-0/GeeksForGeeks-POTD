class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: Find length of linked list
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: Check for invalid k
        if (k > n) return head;

        // Step 3: If kth node from start and end are same
        if (2 * k - 1 == n) return head;

        // Step 4: Find kth node from start (x) and its previous
        Node* x_prev = NULL;
        Node* x = head;
        for (int i = 1; i < k; i++) {
            x_prev = x;
            x = x->next;
        }

        // Step 5: Find kth node from end (y) and its previous
        Node* y_prev = NULL;
        Node* y = head;
        for (int i = 1; i < n - k + 1; i++) {
            y_prev = y;
            y = y->next;
        }

        // Step 6: Swap previous nodes' next
        if (x_prev) x_prev->next = y;
        if (y_prev) y_prev->next = x;

        // Step 7: Swap next pointers
        Node* tempNext = x->next;
        x->next = y->next;
        y->next = tempNext;

        // Step 8: Fix head if needed
        if (k == 1) head = y;
        else if (k == n) head = x;

        return head;
    }
};
