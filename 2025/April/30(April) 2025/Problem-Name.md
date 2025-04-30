# Problem: Find Length of Loop in a Linked List

**Difficulty:** Easy  
**Accuracy:** 44.26%  
**Submissions:** 252K+  
**Points:** 2  
**Average Time:** 30 minutes

## Problem Statement

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

**Note:** `c` is the position (1-based index) of the node to which the last node is connected. If `c` is 0, then there is no loop.

## Input Format
- `head`: The head of a singly linked list.
- `c`: An integer indicating the position (1-based index) of the node the last node should point to in order to form a loop.

## Output Format
- Return the length of the loop if it exists, otherwise return `0`.

## Examples

### Example 1:
**Input:**
```
head: 1 → 2 → 3 → 4 → 5
c = 2
```
**Output:**
```
4
```
**Explanation:**
Loop: 2 → 3 → 4 → 5 → 2. Loop length is 4.

### Example 2:
**Input:**
```
head: 25 → 14 → 19 → 33 → 10 → 21 → 39 → 90 → 58 → 45
c = 4
```
**Output:**
```
7
```
**Explanation:**
Loop: 33 → 10 → 21 → 39 → 90 → 58 → 45 → 33. Loop length is 7.

### Example 3:
**Input:**
```
head: 0 → 1 → 2 → 3
c = 0
```
**Output:**
```
0
```
**Explanation:**
No loop exists.

## Constraints
- 1 ≤ number of nodes ≤ 10^6
- 0 ≤ node.data ≤ 10^6
- 0 ≤ c ≤ n - 1

## Approach
Use Floyd's Cycle Detection Algorithm:
1. Use two pointers, `slow` and `fast`, to detect the loop.
2. If a loop is detected (slow == fast), keep one pointer at that position.
3. Move the other pointer until it comes back to the same node, counting the number of steps to find the loop length.

## Code (C++)
```cpp
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node *slow = head, *fast = head;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Step 2: Count the number of nodes in the loop
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
