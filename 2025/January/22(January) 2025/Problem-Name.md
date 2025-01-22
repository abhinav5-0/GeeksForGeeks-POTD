# Add Two Numbers Represented by Linked Lists

## Problem Statement
You are given the heads of two singly linked lists, `num1` and `num2`, representing two non-negative integers. Each node contains a single digit, and the digits are stored in reverse order (i.e., the least significant digit comes first). Your task is to return the head of the linked list representing the sum of these two numbers.

## Examples

### Example 1:
**Input:**
```
num1 = 4 -> 5
num2 = 3 -> 4 -> 5
```
**Output:**
```
3 -> 9 -> 0
```
**Explanation:**
Given numbers are 45 and 345. Their sum is 390.

### Example 2:
**Input:**
```
num1 = 0 -> 0 -> 6 -> 3
num2 = 0 -> 7
```
**Output:**
```
7 -> 0
```
**Explanation:**
Given numbers are 63 and 7. Their sum is 70.

## Constraints
- 1 <= size of both linked lists <= 10<sup>6</sup>
- 0 <= elements of both linked lists <= 9
- There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

## Approach
1. **Reverse the Input Lists**:
   - Reverse both `num1` and `num2` to facilitate addition starting from the least significant digit.
2. **Add the Numbers**:
   - Use a dummy node to construct the resultant linked list. Iterate through both lists and add corresponding digits, managing carry as necessary.
3. **Reverse the Result**:
   - Reverse the resulting linked list to obtain the sum in the correct order.
4. **Remove Leading Zeros**:
   - Skip any leading zeros in the resultant linked list.

## Implementation
Here is the C++ implementation of the solution:

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* l1, Node* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) sum += l1->data, l1 = l1->next;
            if (l2) sum += l2->data, l2 = l2->next;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        Node* res = reverse(dummy->next);
        delete dummy;
        while (res && res->data == 0 && res->next) {
            Node* temp = res;
            res = res->next;
            delete temp;
        }
        return res;
    }
};

// Utility functions for testing
Node* buildList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    Node* head = new Node(nums[0]);
    Node* tail = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        tail->next = new Node(nums[i]);
        tail = tail->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    Solution solution;
    Node* num1 = buildList({4, 5});
    Node* num2 = buildList({3, 4, 5});

    Node* result = solution.addTwoLists(num1, num2);
    printList(result);

    return 0;
}
```

## Explanation
1. **Reverse Function**:
   - Reverses the linked list to make addition easier.

2. **Add Two Lists**:
   - Iterates through both input lists and adds corresponding digits while managing carry.

3. **Final Cleanup**:
   - Removes leading zeros in the result if necessary.

## Complexity Analysis
- **Time Complexity**: O(max(N, M)) where N and M are the lengths of `num1` and `num2`, respectively. This includes reversing the lists, performing addition, and reversing the result.
- **Space Complexity**: O(max(N, M)) for storing the resultant linked list.

## Test Cases
1. `num1 = 0 -> 0 -> 1, num2 = 9 -> 9`
   - Output: `0 -> 0 -> 0 -> 1`
2. `num1 = 1 -> 0 -> 0, num2 = 1`
   - Output: `1 -> 0 -> 1`
3. `num1 = 9 -> 9, num2 = 1`
   - Output: `0 -> 0 -> 1`

## Contributions
Feel free to contribute to this repository by adding more test cases, optimizing the code, or improving documentation.


