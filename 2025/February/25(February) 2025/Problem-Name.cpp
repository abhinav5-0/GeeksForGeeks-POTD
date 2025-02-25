class Solution {
  public:
    int getMaxArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // Monotonic increasing stack
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};
