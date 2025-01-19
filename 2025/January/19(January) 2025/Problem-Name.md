# Rotate a Linked List

## Problem Statement
Given the head of a singly linked list, the task is to **left rotate** the linked list `k` times.

### Examples

**Example 1**:
Input: `head = 10 -> 20 -> 30 -> 40 -> 50, k = 4`

Output: `50 -> 10 -> 20 -> 30 -> 40`

Explanation:
- Rotate 1: `20 -> 30 -> 40 -> 50 -> 10`
- Rotate 2: `30 -> 40 -> 50 -> 10 -> 20`
- Rotate 3: `40 -> 50 -> 10 -> 20 -> 30`
- Rotate 4: `50 -> 10 -> 20 -> 30 -> 40`

**Example 2**:
Input: `head = 10 -> 20 -> 30 -> 40, k = 6`

Output: `30 -> 40 -> 10 -> 20`

### Constraints
- `1 <= number of nodes <= 10^5`
- `0 <= k <= 10^9`
- `0 <= data of node <= 10^9`

---

## Approach
The following steps provide an efficient solution for rotating the linked list:

1. **Edge Cases**:
   - If the list is empty (`head == NULL`), has only one node (`head->next == NULL`), or no rotation is needed (`k == 0`), return `head` as it is.

2. **Compute Length**:
   - Traverse the list to find its length (`len`).
   - Link the last node of the list back to the head to create a circular linked list.

3. **Effective Rotations**:
   - Calculate the effective rotations using `k % len`.
   - If `k % len == 0`, return the original `head` (no change needed).

4. **Find the New Head and Tail**:
   - Traverse `k` nodes from the current head to identify the new tail.
   - The node after the new tail will become the new head.

5. **Break the Circle**:
   - Disconnect the circular link by setting the `next` of the new tail to `NULL`.

---

## Implementation
Here is the implementation of the above logic in C++:

```cpp
class Solution {
 public:
  Node* rotate(Node* head, int k) {
    if (!head || !head->next || !k) return head;  // Handle edge cases

    // Step 1: Find length of the list and link last node to head
    int len = 1;
    Node* tail = head;
    while (tail->next) {
      tail = tail->next;
      len++;
    }
    tail->next = head;  // Make the list circular

    // Step 2: Calculate effective rotations
    k %= len;
    if (!k) {
      tail->next = nullptr;  // Break the circular connection
      return head;
    }

    // Step 3: Find the new tail and head
    Node* newTail = head;
    for (int i = 1; i < k; i++) {
      newTail = newTail->next;
    }
    Node* newHead = newTail->next;

    // Step 4: Break the circular connection
    newTail->next = nullptr;

    return newHead;
  }
};
```

---

## Complexity Analysis
1. **Time Complexity**:
   - Calculating the length of the list: `O(n)`
   - Traversing to the new head: `O(k % n)`
   - Overall: `O(n)`

2. **Space Complexity**:
   - `O(1)` as no extra space is used.

---

## Key Observations
- For very large values of `k`, calculating `k % len` ensures we do not perform unnecessary rotations.
- The circular linking step is crucial for efficient traversal and breaking the connection at the correct point.

---

## Example Walkthrough

### Input
List: `10 -> 20 -> 30 -> 40 -> 50`  
Rotations: `k = 4`

### Execution
1. Compute length: `len = 5`
2. Effective rotations: `k = 4 % 5 = 4`
3. Circular link: `50 -> 10`
4. Traverse to new tail: After `4` steps, `newTail = 40`
5. Set `newHead = 50`
6. Break circular link: `40 -> NULL`

### Output
`50 -> 10 -> 20 -> 30 -> 40`

---

## Edge Cases
- Single-node list
- `k = 0`
- `k` is a multiple of the list length

---

## Conclusion
This solution ensures correctness and efficiency for rotating a singly linked list, handling all edge cases effectively.

