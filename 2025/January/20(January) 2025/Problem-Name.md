# Merge Two Sorted Linked Lists

This project demonstrates a solution to merge two sorted linked lists into a single sorted linked list.

## Problem Statement

Given the heads of two sorted linked lists, the task is to merge them into a single sorted linked list and return its head.

### Examples

#### Example 1:
**Input**:  
List 1: `5 -> 10 -> 15 -> 40`  
List 2: `2 -> 3 -> 20`  

**Output**:  
`2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40`

---

#### Example 2:
**Input**:  
List 1: `1 -> 1`  
List 2: `2 -> 4`  

**Output**:  
`1 -> 1 -> 2 -> 4`

---

## Approach

1. **Dummy Node**:
   - Create a dummy node to simplify edge cases.
2. **Two-Pointer Technique**:
   - Compare the current nodes of both lists and append the smaller one to the merged list.
3. **Remaining Nodes**:
   - Append the remaining nodes of the non-empty list after one list is exhausted.

---

## Algorithm

1. Create a dummy node.
2. Traverse both lists:
   - Compare the nodes and link the smaller node to the merged list.
   - Move the pointer of the smaller node's list forward.
3. Append any remaining nodes from the non-empty list.
4. Return the merged list starting from `dummy->next`.

---

## Complexity

- **Time Complexity**: \(O(n + m)\), where \(n\) and \(m\) are the lengths of the two linked lists.
- **Space Complexity**: \(O(1)\) (in-place merging).

---

## Implementation

```cpp
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        tail->next = (head1 != nullptr) ? head1 : head2;

        Node* mergedHead = dummy->next;
        delete dummy;
        return mergedHead;
    }
};
