# Swap Kth Nodes from Ends

**Difficulty:** Medium
**Accuracy:** 35.5%
**Submissions:** 65K+
**Points:** 4
**Average Time:** 45m

---

## Problem Statement

Given the head of a singly linked list and an integer `k`. Swap the `k`th node (1-based index) from the beginning and the `k`th node from the end of the linked list. Return the head of the final formed list and if it's not possible to swap the nodes, return the original list.

### Examples

**Input:** k = 1
**Output:** `5 -> 2 -> 3 -> 4 -> 1`
**Explanation:** The 1st node from the beginning and the 1st node from the end are swapped.

**Input:** k = 2
**Output:** `5 -> 10 -> 8 -> 5 -> 9 -> 3`
**Explanation:** The 2nd node from the beginning and the 2nd node from the end are swapped.

---

## Constraints

* 1 ≤ list size ≤ 10^4
* 1 ≤ node->data ≤ 10^6
* 1 ≤ k ≤ 10^4

---

## Approach

1. **Find length of list (`n`)**.
2. If `k > n`, swapping is not possible → return `head`.
3. If nodes are the same (`k == n - k + 1`), no swap needed → return `head`.
4. Otherwise:

   * Find the `k`th node from start (`x`) and its previous (`x_prev`).
   * Find the `k`th node from end (`y`) and its previous (`y_prev`).
5. Swap nodes:

   * Update `x_prev->next` and `y_prev->next` correctly.
   * Swap `x->next` and `y->next`.
6. Adjust head if the swapped node is at position 1 or `n`.

---

## C++ Implementation

```cpp
class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: Find length of linked list
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Step 2: Check for invalid k
        if (k > n) return head;

        // Step 3: If kth node from start and end are same
        if (2 * k - 1 == n) return head;

        // Step 4: Find kth node from start (x) and its previous
        Node* x_prev = NULL;
        Node* x = head;
        for (int i = 1; i < k; i++) {
            x_prev = x;
            x = x->next;
        }

        // Step 5: Find kth node from end (y) and its previous
        Node* y_prev = NULL;
        Node* y = head;
        for (int i = 1; i < n - k + 1; i++) {
            y_prev = y;
            y = y->next;
        }

        // Step 6: Swap previous nodes' next
        if (x_prev) x_prev->next = y;
        if (y_prev) y_prev->next = x;

        // Step 7: Swap next pointers
        Node* tempNext = x->next;
        x->next = y->next;
        y->next = tempNext;

        // Step 8: Fix head if needed
        if (k == 1) head = y;
        else if (k == n) head = x;

        return head;
    }
};
```

---

## Example Walkthrough

**Input:** `1 -> 2 -> 3 -> 4 -> 5`, k = 1
**Output:** `5 -> 2 -> 3 -> 4 -> 1`

**Input:** `5 -> 9 -> 8 -> 5 -> 10 -> 3`, k = 2
**Output:** `5 -> 10 -> 8 -> 5 -> 9 -> 3`
