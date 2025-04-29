# Sort a Linked List of 0s, 1s and 2s

## Problem Statement
Given the head of a linked list where nodes can contain values **0**, **1**, and **2** only, your task is to rearrange the list so that:
- All **0s** appear at the beginning,
- Followed by all **1s**,
- Followed by all **2s**.

You are required to perform this operation in-place without creating new linked list nodes.

## Constraints
- $1 \leq$ Number of nodes $\leq 10^6$
- $0 \leq$ Node values $\leq 2$

## Examples

### Example 1:
**Input:**
```
1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
```
**Output:**
```
0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
```

### Example 2:
**Input:**
```
2 → 2 → 0 → 1
```
**Output:**
```
0 → 1 → 2 → 2
```

## Approach

### Counting Approach
1. Traverse the linked list once and count the number of 0s, 1s, and 2s.
2. Traverse the list again and update the nodes' data based on the counts.

This approach:
- Does **not** require extra space (besides a few variables).
- Is efficient and easy to implement.

### Code
```cpp
class Solution {
  public:
    Node* segregate(Node* head) {
        int count[3] = {0, 0, 0};
        Node* temp = head;

        // Count the number of 0s, 1s, and 2s
        while (temp != nullptr) {
            count[temp->data]++;
            temp = temp->next;
        }

        // Update the linked list
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            if (count[i] == 0) {
                i++;
            } else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }

        return head;
    }
};
```

## Time and Space Complexity
- **Time Complexity:** $O(N)$ (where N is the number of nodes)
- **Space Complexity:** $O(1)$ (constant space)

---

## Optional Alternative Approach
**Three-Pointer Technique**
- Create three dummy nodes for 0s, 1s, and 2s.
- Attach nodes accordingly while traversing.
- Connect the lists and update head.

(Recommended if rearranging nodes themselves is required rather than just values.)

---

## Tags
`Linked List`, `Sorting`, `Counting Sort`, `Two-Pointer`

