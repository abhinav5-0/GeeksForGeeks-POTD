/*
Problem: Merge K Sorted Linked Lists
Difficulty: Medium

Given an array arr[] of n sorted linked lists of different sizes, merge all these lists into a single sorted linked list.

Constraints:
1 ≤ total no. of nodes ≤ 10^5
1 ≤ node->data ≤ 10^3
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap
        }
    };

    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        // Push head of each list into priority queue
        for (auto listHead : arr) {
            if (listHead != nullptr)
                pq.push(listHead);
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while (!pq.empty()) {
            Node* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;
            
            if (curr->next != nullptr)
                pq.push(curr->next);
        }
        
        return dummy->next;
    }
};
