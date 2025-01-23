# Clone List with Next and Random

## Problem Statement

You are given a special linked list with `n` nodes where each node has two pointers:
- A `next` pointer that points to the next node in the singly linked list.
- A `random` pointer that points to a random node in the linked list.

Your task is to construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the `next` and `random` pointers of the new nodes should point to new nodes in the copied list, such that it also represents the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

### Note
The original linked list should remain unchanged.

## Examples

### Example 1
**Input:** `head = [[1, 3], [3, 3], [5, NULL], [9, 3]]`  
**Output:** `head = [[1, 3], [3, 3], [5, NULL], [9, 3]]`  
**Explanation:**  
- Node 1 points to Node 2 as its `NEXT` and Node 3 as its `RANDOM`.
- Node 2 points to Node 3 as its `NEXT` and Node 3 as its `RANDOM`.
- Node 3 points to Node 4 as its `NEXT` and `NULL` as its `RANDOM`.
- Node 4 points to `NULL` as its `NEXT` and Node 3 as its `RANDOM`.

### Example 2
**Input:** `head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]`  
**Output:** `head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]`  
**Explanation:**  
- Node 1 points to Node 2 as its `NEXT` and Node 3 as its `RANDOM`.
- Node 2 points to Node 3 as its `NEXT` and Node 1 as its `RANDOM`.
- Node 3 points to Node 4 as its `NEXT` and Node 5 as its `RANDOM`.
- Node 4 points to Node 5 as its `NEXT` and Node 3 as its `RANDOM`.
- Node 5 points to `NULL` as its `NEXT` and Node 2 as its `RANDOM`.

### Example 3
**Input:** `head = [[7, NULL], [7, NULL]]`  
**Output:** `head = [[7, NULL], [7, NULL]]`  
**Explanation:**  
- Node 1 points to Node 2 as its `NEXT` and `NULL` as its `RANDOM`.
- Node 2 points to `NULL` as its `NEXT` and `NULL` as its `RANDOM`.

## Constraints
- `1 <= n <= 100`
- `0 <= node->data <= 1000`

## Solution Approach

1. **Create a Copy of Each Node**: For each node in the original list, create a new node with the same value and insert it right after the original node.
2. **Set the Random Pointers**: Iterate through the modified list and set the `random` pointers for the newly created nodes.
3. **Separate the Two Lists**: Restore the original list and extract the cloned list at the same time.

## Implementation

Here is the implementation of the solution:

```cpp
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
