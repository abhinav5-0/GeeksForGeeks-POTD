# Reverse a Linked List

## Problem Statement
Given the head of a linked list, reverse the list and return the new head.

### Examples

#### Example 1:
**Input:**
```
head: 1 -> 2 -> 3 -> 4 -> NULL
```
**Output:**
```
head: 4 -> 3 -> 2 -> 1 -> NULL
```

#### Example 2:
**Input:**
```
head: 2 -> 7 -> 10 -> 9 -> 8 -> NULL
```
**Output:**
```
head: 8 -> 9 -> 10 -> 7 -> 2 -> NULL
```

#### Example 3:
**Input:**
```
head: 10 -> NULL
```
**Output:**
```
head: 10 -> NULL
```

### Constraints
- \(1 \leq \text{number of nodes}, \text{data of nodes} \leq 10^5\)

## Solution Logic
1. Use three pointers:
   - `prev` (initially `NULL`)
   - `curr` (points to `head` initially)
   - `next` (to temporarily store `curr->next`)

2. While traversing the list:
   - Save the next node: `next = curr->next`.
   - Reverse the current node's pointer: `curr->next = prev`.
   - Move forward: `prev = curr; curr = next`.

3. Once traversal is complete (`curr == NULL`), `prev` points to the new head.

4. Return `prev`.

## Code Implementation (C++)

```cpp
class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* prev = NULL;  // Previous node
        Node* curr = head;  // Current node
        Node* next = NULL;  // Next node

        while (curr != NULL) {
            // Save the next node
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
```

## Complexity Analysis
- **Time Complexity:** \(O(N)\), where \(N\) is the number of nodes in the list, as each node is processed exactly once.
- **Space Complexity:** \(O(1)\), as no additional data structures are used.

## Dry Run Example
### Input:
```
head: 1 -> 2 -> 3 -> 4 -> NULL
```
### Iterations:
| `prev` | `curr` | `next` | Updated List |
|--------|--------|--------|---------------|
| NULL   | 1      | 2      | 1 -> NULL     |
| 1      | 2      | 3      | 2 -> 1 -> NULL|
| 2      | 3      | 4      | 3 -> 2 -> 1 -> NULL|
| 3      | 4      | NULL   | 4 -> 3 -> 2 -> 1 -> NULL|

### Output:
```
head: 4 -> 3 -> 2 -> 1 -> NULL
