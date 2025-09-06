# Find Length of Loop in Linked List

## Problem Statement

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

> Note: Internally, `pos` (1-based index) denotes the position of the node that tail's next pointer is connected to. If `pos = 0`, it means there is no loop.

### Examples

**Example 1:**

* Input: pos = 2
* Output: 4
* Explanation: There exists a loop in the linked list and the length of the loop is 4.

**Example 2:**

* Input: pos = 3
* Output: 3
* Explanation: The loop is from 19 to 10. So length of loop is 19 → 33 → 10 = 3.

**Example 3:**

* Input: pos = 0
* Output: 0
* Explanation: There is no loop.

### Constraints

* 1 ≤ number of nodes ≤ 10^5
* 1 ≤ node->data ≤ 10^4
* 0 ≤ pos < number of nodes

### Node Definition

```cpp
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
```

## Solution Approach

We can use **Floyd’s Cycle-Finding Algorithm** (Tortoise and Hare) to detect a loop and then count the nodes in the loop.

### Steps

1. Initialize two pointers, `slow` and `fast`, at the head.
2. Move `slow` by 1 step and `fast` by 2 steps.
3. If `slow` and `fast` meet, a loop exists.
4. To find the loop length, keep one pointer fixed and move the other pointer until it comes back to the meeting point, counting the nodes.

### C++ Implementation

```cpp
class Solution {
public:
    int lengthOfLoop(Node *head) {
        if (!head) return 0;
        
        Node* slow = head;
        Node* fast = head;

        // Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // Loop detected
                int count = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }

        return 0; // No loop
    }
};
```

### Complexity Analysis

* **Time Complexity:** O(N) — each node is visited at most twice.
* **Space Complexity:** O(1) — no extra space is used.

### Notes

* Works for empty lists and lists with a single node.
* Efficient for large lists up to 10^5 nodes.
