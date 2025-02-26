class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> s;
        
        // Find the previous smaller element index for each element
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) left[i] = s.top();
            s.push(i);
        }

        // Clear the stack for next computation
        while (!s.empty()) s.pop();

        // Find the next smaller element index for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty()) right[i] = s.top();
            s.push(i);
        }

        // Create an array to store maximum of minimums for every window size
        vector<int> ans(n + 1, 0);

        // Compute window size for each element and update ans[]
        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1;
            ans[windowSize] = max(ans[windowSize], arr[i]);
        }

        // Fill the remaining entries
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        // Remove the first element (index 0 is unused)
        ans.erase(ans.begin());

        return ans;
    }
};
