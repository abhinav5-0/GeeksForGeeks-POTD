class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> res(n, -1);
        stack<int> st;

        // Step 1: Count frequencies of each number
        for (int num : arr) {
            freq[num]++;
        }

        // Step 2: Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Pop elements from stack until we find one with higher frequency
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) {
                st.pop();
            }

            // If stack is not empty, top element is the answer
            if (!st.empty()) {
                res[i] = arr[st.top()];
            }

            // Push current index into the stack
            st.push(i);
        }

        return res;
    }
};
