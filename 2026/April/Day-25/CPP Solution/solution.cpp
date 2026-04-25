class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;
        
        for (int x : arr) {
            while (!st.empty() && st.back() * x < 0) {
                if (abs(st.back()) > abs(x)) {
                    x = st.back();
                    st.pop_back();
                } else if (abs(st.back()) < abs(x)) {
                    st.pop_back();
                } else {
                    st.pop_back();
                    x = 0;
                    break;
                }
            }
            if (x != 0) st.push_back(x);
        }
        
        return st;
    }
};
