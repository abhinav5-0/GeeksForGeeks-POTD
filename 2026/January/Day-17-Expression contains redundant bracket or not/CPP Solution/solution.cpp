class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                bool hasOperator = false;

                while (!st.empty() && st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        hasOperator = true;
                }

                // pop the opening bracket '('
                if (!st.empty()) st.pop();

                // no operator found → redundant
                if (!hasOperator) return true;
            } 
            else {
                st.push(ch);
            }
        }
        return false;
    }
};
