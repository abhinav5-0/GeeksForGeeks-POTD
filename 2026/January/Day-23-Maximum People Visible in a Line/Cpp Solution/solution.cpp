class Solution {
public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> st;

        // Left side visibility
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                left[i]++;
                st.pop();
            }
            if (!st.empty()) left[i]++;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Right side visibility
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                right[i]++;
                st.pop();
            }
            if (!st.empty()) right[i]++;
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, left[i] + right[i] + 1);

        return ans;
    }
};
