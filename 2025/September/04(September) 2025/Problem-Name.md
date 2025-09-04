# Linked List Group Reverse

## Problem
You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.

**Note:** If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

### Examples

**Input:** k = 2  
**Output:** 2 -> 1 -> 4 -> 3 -> 6 -> 5  
Explanation: Linked List is reversed in a group of size k = 2.

**Input:** k = 4  
**Output:** 4 -> 3 -> 2 -> 1 -> 6 -> 5  
Explanation: Linked List is reversed in a group of size k = 4.

### Constraints
- 1 ≤ size of linked list ≤ 10^5  
- 0 ≤ node->data ≤ 10^6  
- 1 ≤ k ≤ size of linked list

---

## C++ Implementation

```cpp
/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prevGroupEnd = dummy;
        Node* curr = head;

        while (curr) {
            // Count k nodes ahead
            Node* temp = curr;
            int count = 0;
            while (temp && count < k) {
                temp = temp->next;
                count++;
            }

            // If less than k, still reverse (per problem statement)
            if (count > 0) {
                Node* groupHead = curr;
                Node* prev = NULL;
                Node* next = NULL;
                int c = 0;

                // Reverse 'count' nodes (even if less than k)
                while (curr && c < count) {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                    c++;
                }

                // Connect previous group end with new head
                prevGroupEnd->next = prev;
                prevGroupEnd = groupHead; // old head becomes end
            }
        }

        return dummy->next;
    }
};
