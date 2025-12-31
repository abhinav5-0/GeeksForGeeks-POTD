# Palindrome Linked List

**Difficulty:** Medium
**Accuracy:** 41.48%
**Average Time:** 20m

---

## Problem Statement

You are given the head of a singly linked list of positive integers. Your task is to determine whether the linked list is a **palindrome**.

A linked list is called a palindrome if it reads the same forward and backward.

---

## Examples

### Example 1

**Input:**

```
1 -> 2 -> 1 -> 1 -> 2 -> 1
```

**Output:**

```
true
```

**Explanation:**
The linked list reads the same from left to right and right to left.

---

### Example 2

**Input:**

```
10 -> 20 -> 30 -> 40 -> 50
```

**Output:**

```
false
```

**Explanation:**
The linked list is not the same when reversed.

---

## Constraints

* `1 ≤ number of nodes ≤ 10^5`
* `0 ≤ node->data ≤ 10^3`

---

## Approach (Optimal)

We solve this problem in **O(n) time** and **O(1) extra space** using the following steps:

1. Use **slow and fast pointers** to find the middle of the linked list.
2. **Reverse the second half** of the list.
3. **Compare** the first half with the reversed second half.
4. If all corresponding elements match, the list is a palindrome.

---

## C++ Implementation

```cpp
class Solution {
  public:
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        Node *prev = nullptr;
        Node *curr = slow->next;
        while (curr) {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare both halves
        Node *first = head;
        Node *second = prev;
        while (second) {
            if (first->data != second->data)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Summary

This approach efficiently checks whether a singly linked list is a palindrome without using extra memory, making it optimal for large inputs.
