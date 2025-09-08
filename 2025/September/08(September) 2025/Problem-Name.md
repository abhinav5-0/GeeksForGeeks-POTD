## Merge Sort for Linked List

### Problem Statement
You are given the head of a linked list. You have to sort the given linked list using **Merge Sort**.

---

### Examples
**Input:**
```
Unsorted Linked List: 50 -> 20 -> 60 -> 40 -> 10 -> 30
```
**Output:**
```
10 -> 20 -> 30 -> 40 -> 50 -> 60
```

**Input:**
```
Unsorted Linked List: 9 -> 5 -> 8 -> 2
```
**Output:**
```
2 -> 5 -> 8 -> 9
```

---

### Constraints
- 1 ≤ number of nodes ≤ 10^5
- 0 ≤ node->data ≤ 10^6

---

### Node Class Definition
```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
```

---

### Solution
```cpp
class Solution {
  public:
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        Node* result = nullptr;
        
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
    
    // Function to find the middle of the linked list
    Node* getMiddle(Node* head) {
        if (!head) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;  // middle node
    }
    
    // Main mergeSort function
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;  // base case
        
        // Step 1: Split the list into halves
        Node* middle = getMiddle(head);
        Node* nextToMiddle = middle->next;
        middle->next = nullptr;
        
        // Step 2: Recursively sort both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextToMiddle);
        
        // Step 3: Merge sorted halves
        return merge(left, right);
    }
};
```

---

### Complexity Analysis
- **Time Complexity:** `O(N log N)` → Splitting takes `log N`, merging takes `O(N)`.
- **Space Complexity:** `O(log N)` → Due to recursion stack.

---
