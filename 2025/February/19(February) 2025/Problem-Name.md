# Merge K Sorted Lists

## Overview
This program merges K sorted linked lists into a single sorted linked list using a **min-heap (priority queue)** approach. The implementation ensures efficiency with a time complexity of **O(N log K)**.

## Approach
1. **Min-Heap (Priority Queue)**: Utilized to always extract the smallest node.
2. **Push First Nodes**: Insert the head node of each linked list into the heap.
3. **Extract Min and Add Next Node**: Extract the smallest node, attach it to the merged list, and insert its next node (if present).

## Time Complexity
- Each insertion and extraction operation in the priority queue takes **O(log K)**.
- Since we process **N** nodes, the overall complexity is **O(N log K)**.

## Example Usage
```
Input:
3
2
1 3
1
8
3
4 5 6

Output:
1 3 4 5 6 8
```

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;  // Min-heap based on node values
        }
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        // Push the first node of each list into the heap
        for (Node* list : arr) {
            if (list) pq.push(list);
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while (!pq.empty()) {
            Node* minNode = pq.top();
            pq.pop();
            
            tail->next = minNode;
            tail = tail->next;
            
            if (minNode->next) {
                pq.push(minNode->next);
            }
        }
        
        return dummy->next;
    }
};

void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Node*> v(n);
        
        for (int i = 0; i < n; i++) {
            int size;
            cin >> size;
            Node* head = nullptr, *tail = nullptr;
            for (int j = 0; j < size; j++) {
                int x;
                cin >> x;
                Node* newNode = new Node(x);
                if (!head) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            v[i] = head;
        }
        
        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }
    return 0;
}
```
