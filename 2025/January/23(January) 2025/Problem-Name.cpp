class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;

        Node* current = head;
        while (current) {
            Node* copy = new Node(current->data);
            copy->next = current->next;
            current->next = copy;
            current = copy->next; // Move to the next original node
        }

        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next; // Set the random pointer of the copy
            }
            current = current->next->next; // Move to the next original node
        }

        Node* original = head;
        Node* copyHead = head->next; // The head of the copied list
        Node* copy = copyHead;

        while (original) {
            original->next = original->next->next; // Restore the original list
            if (copy->next) {
                copy->next = copy->next->next; // Link the copied nodes
            }
            original = original->next; // Move to the next original node
            copy = copy->next; // Move to the next copied node
        }

        return copyHead; // Return the head of the copied list
    }
};
