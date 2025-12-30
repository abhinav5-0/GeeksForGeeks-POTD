# Add Number Linked Lists

## Problem Statement

You are given the head of two singly linked lists `head1` and `head2` representing two non-negative integers. Each node contains a single digit. The digits are stored in **forward order** (most significant digit first).

Your task is to return the head of a linked list representing the **sum** of these two numbers.

**Note:**

* The input lists may contain leading zeros.
* The output list **must not** contain leading zeros (unless the result is zero itself).

---

## Examples

### Example 1

**Input:**

* List 1: `1 -> 2 -> 3`
* List 2: `9 -> 9 -> 9`

**Output:**

```
1 -> 1 -> 2 -> 2
```

**Explanation:** 123 + 999 = 1122

### Example 2

**Input:**

* List 1: `6 -> 3`
* List 2: `7`

**Output:**

```
7 -> 0
```

**Explanation:** 63 + 7 = 70

---

## Constraints

* `1 ≤ Number of nodes in head1, head2 ≤ 10^5`
* `0 ≤ node->data ≤ 9`

---

## Approach

1. **Reverse both linked lists** to process digits from least significant to most significant.
2. **Add corresponding digits** along with carry.
3. **Store the result** in a new linked list.
4. **Reverse the result list** to restore forward order.
5. **Remove leading zeros** from the final list.

---

## C++ Implementation

```cpp
class Solution {
  private:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        int carry = 0;
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while (head1 || head2 || carry) {
            int sum = carry;
            
            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }
            
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }
        
        // Reverse the result list
        Node* result = reverse(dummy->next);
        
        // Remove leading zeros
        while (result && result->data == 0 && result->next) {
            result = result->next;
        }
        
        return result;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n + m)`
* **Space Complexity:** `O(n + m)`

Where `n` and `m` are the lengths of the two linked lists.

---

## Key Takeaways

* Reversing linked lists simplifies addition when digits are in forward order.
* Always handle carry properly.
* Remove leading zeros to match the problem constraints.
