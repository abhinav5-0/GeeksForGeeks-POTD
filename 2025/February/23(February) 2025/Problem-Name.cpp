class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1); // Initialize result with -1
        stack<int> s; // Monotonic decreasing stack

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack that are smaller than or equal to arr[i]
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }

            // If stack is not empty, the top is the next greater element
            if (!s.empty()) {
                result[i] = s.top();
            }

            // Push current element to stack
            s.push(arr[i]);
        }
        return result;
    }
};
