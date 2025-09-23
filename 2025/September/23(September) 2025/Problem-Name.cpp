class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        
        // Step 1: Push all elements into stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        
        // Step 2: Pop from stack and push back into queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};
