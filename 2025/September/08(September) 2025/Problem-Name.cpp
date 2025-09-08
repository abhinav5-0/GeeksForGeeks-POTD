class Solution {
  public:
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        Node* result = nullptr;
        
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
    
    // Function to find the middle of the linked list
    Node* getMiddle(Node* head) {
        if (!head) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;  // middle node
    }
    
    // Main mergeSort function
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;  // base case
        
        // Step 1: Split the list into halves
        Node* middle = getMiddle(head);
        Node* nextToMiddle = middle->next;
        middle->next = nullptr;
        
        // Step 2: Recursively sort both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextToMiddle);
        
        // Step 3: Merge sorted halves
        return merge(left, right);
    }
};
