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

