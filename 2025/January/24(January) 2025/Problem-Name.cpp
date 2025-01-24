class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create a copy of each node and insert it right after the original node
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->data);
            copy->next = current->next;
            current->next = copy;
            current = copy->next; // Move to the next original node
        }

        // Step 2: Set the random pointers for the copied nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next; // Set the random pointer of the copy
            }
            current = current->next->next; // Move to the next original node
        }

        // Step 3: Separate the two lists
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
