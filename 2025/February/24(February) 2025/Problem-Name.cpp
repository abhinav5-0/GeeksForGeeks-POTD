class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        stack<int> st; // Stack to store indices
        
        for (int i = 0; i < n; i++) {
            // Pop elements from stack while the stack is not empty and the top element is smaller or equal to arr[i]
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            // If stack is empty, span is i + 1 (all previous elements are smaller)
            span[i] = (st.empty()) ? (i + 1) : (i - st.top());
            
            // Push this element's index to stack
            st.push(i);
        }
        
        return span;
    }
};
