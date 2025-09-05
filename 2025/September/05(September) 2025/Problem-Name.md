# Sort a Linked List of 0s, 1s, and 2s

## Problem Statement
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only, rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

### Examples
**Input:** 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2  
**Output:** 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

**Input:** 2 → 2 → 0 → 1  
**Output:** 0 → 1 → 2 → 2

### Constraints
- 1 ≤ no. of nodes ≤ 10^6
- 0 ≤ node->data ≤ 2

Node definition:
```cpp
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
```

---

## 🔹 Approach 1: Counting Method (Simple)
1. Traverse the linked list and count the number of 0s, 1s, and 2s.
2. Traverse again and overwrite node values in order.

- Time Complexity: **O(N)**
- Space Complexity: **O(1)**

---

## 🔹 Approach 2: Linked List Rearrangement (Efficient & Clean)
Instead of modifying data, rearrange nodes using three dummy linked lists.

### Steps
1. Create three dummy nodes: one for 0s, one for 1s, and one for 2s.
2. Traverse the list and link nodes to the respective list.
3. Merge the three lists.
4. Return the new head.

### Implementation
```cpp
class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        // Dummy nodes for 0, 1, 2 lists
        Node* zeroD = new Node(-1);
        Node* oneD  = new Node(-1);
        Node* twoD  = new Node(-1);

        // Tails for each list
        Node* zero = zeroD;
        Node* one  = oneD;
        Node* two  = twoD;

        // Traverse original list
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            }
            else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            }
            else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect the three lists
        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        // New head
        head = zeroD->next;

        // Cleanup dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
    }
};
```

---

✅ Works in **O(N)** time and **O(1)** extra space.  
✅ Rearranges nodes without modifying data.  

---
