# Insert in Sorted Circular Linked List

**Difficulty:** Medium
**Accuracy:** 25.56%
**Submissions:** 131K+
**Points:** 4
**Average Time:** 20 mins

## Problem Statement

Given a **sorted circular linked list**, insert a new node into the list such that it remains a **sorted circular linked list**.

### Examples

**Example 1:**

```
Input: head = 1 -> 2 -> 4, data = 2
Output: 1 -> 2 -> 2 -> 4
Explanation: We can add 2 after the first 2.
```

**Example 2:**

```
Input: head = 1 -> 4 -> 7 -> 9, data = 5
Output: 1 -> 4 -> 5 -> 7 -> 9
Explanation: We can add 5 after the node with value 4.
```

## Constraints

* 2 <= number of nodes <= 10^6
* 0 <= node->data <= 10^6
* 0 <= data <= 10^6

## Approach

1. Handle the case where the list is empty.
2. Traverse the circular linked list to find the appropriate place for insertion:

   * If the new data fits between two existing nodes.
   * If the new data is smaller than the current minimum or larger than the current maximum.
3. Adjust the links to insert the new node.
4. If the inserted node becomes the new head, update and return it.

## C++ Implementation

```cpp
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // Case 1: Empty list
        if (head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        // Case 2: Insert before head (new minimum) or in correct sorted position
        while (true) {
            // Case a: Insert between two nodes
            if (curr->data <= data && curr->next->data >= data) {
                break;
            }

            // Case b: Insert at the turning point (max to min)
            if (curr->data > curr->next->data) {
                if (data >= curr->data || data <= curr->next->data) {
                    break;
                }
            }

            curr = curr->next;

            // If we complete one full circle
            if (curr == head) break;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        // If the new node is the new head (new min), return it
        if (data < head->data) return newNode;
        return head;
    }
};
```

## Notes

* Ensure proper circular behavior by checking when we’ve looped back to the head.
* Take care of edge cases where the data is the new minimum or maximum.

## Tags

Linked List, Circular List, Insertion, Sorting
