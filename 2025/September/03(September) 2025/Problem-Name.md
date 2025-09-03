## Problem: Reverse a Doubly Linked List

You are given the head of a doubly linked list. You have to reverse the doubly linked list and return its head.

### Examples

**Input:**
```
3 <-> 4 <-> 5
```
**Output:**
```
5 <-> 4 <-> 3
```

**Input:**
```
75 <-> 122 <-> 59 <-> 196
```
**Output:**
```
196 <-> 59 <-> 122 <-> 75
```

### Constraints
- 1 ≤ number of nodes ≤ 10^6  
- 0 ≤ node->data ≤ 10^4  

### Node Structure
```cpp
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
```

### Solution
```cpp
class Solution {
  public:
    Node *reverse(Node *head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        Node* temp = nullptr;
        
        // Traverse and swap next & prev for each node
        while (curr) {
            // Swap
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            
            // Move to the "next" node (which is actually prev after swapping)
            curr = curr->prev;
        }
        
        // After the loop, temp will point to the new head's previous node
        if (temp) head = temp->prev;
        
        return head;
    }
};
```

### Complexity Analysis
- **Time Complexity:** O(N), since each node is visited once.
- **Space Complexity:** O(1), only a few pointers
