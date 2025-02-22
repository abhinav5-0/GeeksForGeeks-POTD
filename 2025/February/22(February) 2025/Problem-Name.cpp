class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        st.push(-1); // Base index to calculate length
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // Update base index for next valid substring
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};
