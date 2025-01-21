# Linked List Group Reverse

## Problem Statement
Given the head of a linked list, the task is to reverse every `k` nodes in the linked list. If the number of nodes is not a multiple of `k`, then the left-out nodes at the end should be considered as a group and must also be reversed.

### Examples:

#### Input:
```
head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
```
#### Output:
```
4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5
```
**Explanation:** The first 4 elements `1, 2, 2, 4` are reversed, and then the next 4 elements `5, 6, 7, 8` are reversed.

#### Input:
```
head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
```
#### Output:
```
3 -> 2 -> 1 -> 5 -> 4
```
**Explanation:** The first 3 elements `1, 2, 3` are reversed, and then the left-out elements `4, 5` are reversed.

### Constraints:
- 1 <= Size of the linked list <= 10<sup>5</sup>
- 1 <= Data of nodes <= 10<sup>6</sup>
- 1 <= k <= Size of the linked list

## Solution
The solution involves reversing the nodes of the linked list in groups of `k`. The key steps are:
1. Traverse the linked list.
2. Reverse `k` nodes at a time.
3. Handle leftover nodes at the end of the list.

### Code Implementation (C++)
```cpp
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* curr = head;
        Node* newHead = nullptr;
        Node* tail = nullptr;

        while (curr) {
            Node* groupPrev = nullptr;
            Node* groupCurr = curr;
            int count = 0;

            // Reverse k nodes in the group
            while (curr && count < k) {
                Node* next = curr->next;
                curr->next = groupPrev;
                groupPrev = curr;
                curr = next;
                count++;
            }

            if (!newHead) newHead = groupPrev;
            if (tail) tail->next = groupPrev;
            tail = groupCurr;
        }

        return newHead;
    }
};

/* Driver program to test above function */
int main(void) {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
```

## Key Functions
### `reverseKGroup`
- **Input:** `head` (pointer to the head of the linked list), `k` (size of the group to reverse).
- **Output:** Pointer to the new head of the modified linked list.
- **Logic:**
  - Reverse `k` nodes iteratively.
  - Link the reversed groups to form the resultant linked list.

### `printList`
- Prints the linked list.

## Complexity Analysis
- **Time Complexity:** O(N), where N is the size of the linked list.
- **Space Complexity:** O(1), as no extra space is used apart from variables.

## How to Run
1. Compile the program using a C++ compiler (e.g., `g++`).
2. Provide test cases as input.
3. Verify the output for correctness.

## Example Input/Output
### Input:
```
1
1 2 2 4 5 6 7 8
4
```
### Output:
```
4 2 2 1 8 7 6 5
~
```

