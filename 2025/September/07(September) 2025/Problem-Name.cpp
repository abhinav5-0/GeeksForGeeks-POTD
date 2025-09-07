#include <queue>

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
