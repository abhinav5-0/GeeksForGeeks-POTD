# Remove Loop in Linked List - Problem of the Day (POTD)

### Difficulty: Medium  
### Accuracy: 27.66%  
### Points: 4  

## Problem Statement

Given the head of a linked list that may contain a loop, the task is to remove the loop from the linked list (if it exists). A loop means that the last node of the linked list is connected back to a node in the same list.

### Input Format
- The head of a singly linked list.
- `pos`: A 1-based index that denotes the position of the node to which the last node points.  
  - If `pos = 0`, it means the last node points to `NULL`, indicating there is no loop.

### Output Format
- The output will be `true` if:
  - The loop is removed, or no loop exists.
  - All other nodes in the linked list remain unchanged.
- Otherwise, the output will be `false`.

---

### Examples

#### Example 1:
```plaintext
Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation:
The linked list contains a loop. The loop is removed successfully.
