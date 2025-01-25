# Problem of the Day: Find the First Node of Loop in Linked List

### Problem Statement
Given the head of a singly linked list, if a loop is present in the list, return the first node of the loop. If no loop exists, return `NULL`.

### Custom Input Format:
- A head of a singly linked list.
- A `pos` (1-based index) which denotes the position of the node to which the last node points to.
  - If `pos = 0`, it means the last node points to `NULL`, indicating no loop.

### Examples

#### Example 1:
Input:
```
1 -> 2 -> 3 -> 4 -> 5
            ^       |
            |-------|
```
Output:
```
3
```
Explanation: There exists a loop in the given linked list, and the first node of the loop is 3.

#### Example 2:
Input:
```
1 -> 2 -> 3 -> 4 -> 5 -> NULL
```
Output:
```
-1
```
Explanation: No loop exists in the above linked list, so the output is -1.

### Constraints:
- `1 <= no. of nodes <= 10^6`
- `1 <= node->data <= 10^6`

---

### Approach
To find the first node of the loop, we can use **Floyd's Cycle Detection Algorithm** (Tortoise and Hare method):

1. **Detect the Loop:**
   - Use two pointers, `slow` and `fast`, starting from the head.
   - Move `slow` one step and `fast` two steps at a time.
   - If they meet, a loop is present.

2. **Find the First Node of the Loop:**
   - Reset `slow` to the head while keeping `fast` at the meeting point.
   - Move both pointers one step at a time until they meet again. The meeting point is the first node of the loop.

3. **Return Result:**
   - If no loop is detected, return `NULL`.
   - If a loop exists, return the first node of the loop.

---

### Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* findFirstNode(Node* head) {
        if (!head || !head->next) return NULL;

        Node* slow = head;
        Node* fast = head;

        // Detect loop using Floyd's Cycle Detection
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected
                break;
            }
        }

        // If no loop exists
        if (!fast || !fast->next) return NULL;

        // Find the first node of the loop
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // First node of the loop
    }
};

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0) return;

    Node *walk = head;
    for (int i = 1; i < position; i++) {
        walk = walk->next;
    }
    tail->next = walk;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int n;
        cin >> n;
        arr.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        Node* head = new Node(arr[0]);
        Node* tail = head;

        for (int i = 1; i < n; i++) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        loopHere(head, tail, k);

        Solution ob;
        Node* ans = ob.findFirstNode(head);
        cout << (ans ? ans->data : -1) << endl;
    }
    return 0;
}
```

---

### Complexity Analysis
- **Time Complexity:** `O(n)`
  - Detecting the loop takes `O(n)` time.
  - Finding the first node of the loop also takes `O(n)` time.
- **Space Complexity:** `O(1)`
  - Only two pointers (`slow` and `fast`) are used.

---

### Explanation of Example
#### Input:
```
1 -> 2 -> 3 -> 4 -> 5
            ^       |
            |-------|
```
- `slow` and `fast` will meet at node `4`.
- Reset `slow` to the head and move both pointers one step at a time.
- They meet at node `3`, which is the start of the loop.

#### Output:
```
3
