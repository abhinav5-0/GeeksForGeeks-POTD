class Solution {
  public:
  
    // Helper function to merge two sorted bottom-linked lists
    Node* merge(Node* a, Node* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;

        Node* result;

        if (a->data < b->data) {
            result = a;
            result->bottom = merge(a->bottom, b);
        } else {
            result = b;
            result->bottom = merge(a, b->bottom);
        }

        // Important: next pointer should be NULL
        result->next = NULL;
        return result;
    }

    Node* flatten(Node* root) {
        // Base case
        if (root == NULL || root->next == NULL)
            return root;

        // Flatten the list on the right
        root->next = flatten(root->next);

        // Merge current list with flattened right list
        root = merge(root, root->next);

        return root;
    }
};
