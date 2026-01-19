class Solution {
public:
    string removeKdig(string &s, int k) {
        string st;  // acts as stack

        for (char c : s) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If k remains, remove from end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int idx = 0;
        while (idx < st.size() && st[idx] == '0') idx++;

        string res = st.substr(idx);
        return res.empty() ? "0" : res;
    }
};
