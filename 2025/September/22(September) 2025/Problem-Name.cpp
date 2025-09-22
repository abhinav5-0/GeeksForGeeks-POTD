class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Find previous smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find next smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        // Initialize result
        vector<int> res(n + 1, 0);

        // Fill answers for length
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            res[len] = max(res[len], arr[i]);
        }

        // Propagate maximums
        for (int i = n - 1; i >= 1; i--) {
            res[i] = max(res[i], res[i + 1]);
        }

        res.erase(res.begin()); // drop index 0 (unused)
        return res;
    }
};
