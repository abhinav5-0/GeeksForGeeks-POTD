class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nextSmaller(n, n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(!st.empty())
                nextSmaller[i] = st.top();

            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += nextSmaller[i] - i;

        return ans;
    }
};
