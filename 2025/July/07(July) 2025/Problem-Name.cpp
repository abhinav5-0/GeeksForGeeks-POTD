class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n, -1); // Initialize result with -1
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; --i) {
            int index = i % n;

            // Pop elements that are less than or equal to arr[index]
            while (!st.empty() && st.top() <= arr[index]) {
                st.pop();
            }

            // If stack is not empty, the top is the next greater element
            if (!st.empty()) {
                result[index] = st.top();
            }

            // Push current element to stack
            st.push(arr[index]);
        }

        return result;
    }
};
