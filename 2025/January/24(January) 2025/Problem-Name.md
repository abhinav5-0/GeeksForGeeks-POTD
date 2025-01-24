# Clone List with Next and Random

## Problem Description
You are given a special linked list with `n` nodes where each node has two pointers:
1. A `next` pointer that points to the next node of the singly linked list.
2. A `random` pointer that points to the random node of the linked list.

Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list, such that it also represents the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

### Constraints
- `1 <= n <= 100`
- `0 <= node->data <= 1000`
- The original linked list should remain unchanged.

## Examples

### Example 1
#### Input
```
head = [[1, 3], [3, 3], [5, NULL], [9, 3]]
```
#### Output
```
head = [[1, 3], [3, 3], [5, NULL], [9, 3]]
```
#### Explanation
- Node 1 points to Node 2 as its `next` and Node 3 as its `random`.
- Node 2 points to Node 3 as its `next` and Node 3 as its `random`.
- Node 3 points to Node 4 as its `next` and `NULL` as its `random`.
- Node 4 points to `NULL` as its `next` and Node 3 as its `random`.

### Example 2
#### Input
```
head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
```
#### Output
```
head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
```
#### Explanation
- Node 1 points to Node 2 as its `next` and Node 3 as its `random`.
- Node 2 points to Node 3 as its `next` and Node 1 as its `random`.
- Node 3 points to Node 4 as its `next` and Node 5 as its `random`.
- Node 4 points to Node 5 as its `next` and Node 3 as its `random`.
- Node 5 points to `NULL` as its `next` and Node 2 as its `random`.

### Example 3
#### Input
```
head = [[7, NULL], [7, NULL]]
```
#### Output
```
head = [[7, NULL], [7, NULL]]
```
#### Explanation
- Node 1 points to Node 2 as its `next` and `NULL` as its `random`.
- Node 2 points to `NULL` as its `next` and `NULL` as its `random`.

## Solution
### Approach
The solution involves three main steps:

1. **Interleave the Original and Copied Nodes**:
   - For each node in the original list, create a new node and insert it immediately after the original node.

2. **Set Random Pointers for Copied Nodes**:
   - Traverse the interleaved list and set the `random` pointer of each copied node using the `random` pointer of its corresponding original node.

3. **Separate the Two Lists**:
   - Restore the original list and extract the copied list by separating the interleaved nodes.

### Implementation
#### C++ Code
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

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

int main() {
    // Sample driver code
    return 0;
}
```

### Explanation of the Steps
1. **Interleaving Nodes**:
   - Each node in the original list is followed by its clone.
   - Example: Original list: `1 -> 2 -> 3`. After this step: `1 -> 1' -> 2 -> 2' -> 3 -> 3'`.

2. **Setting Random Pointers**:
   - Use the `random` pointer of the original node to assign the `random` pointer of its clone.

3. **Separating the Lists**:
   - Detach the cloned nodes from the interleaved list to restore the original list and obtain the cloned list.

### Complexity Analysis
- **Time Complexity**: `O(n)`
  - Traverses the list three times.
- **Space Complexity**: `O(1)`
  - No extra space is used apart from the copied nodes.


