class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        
        for (auto &token : arr) {
            // If token is operator
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;
                
                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = a * b;
                else if (token == "/") {
                    // floor division handling
                    if ((a < 0) ^ (b < 0)) {
                        res = floor((double)a / b);
                    } else {
                        res = a / b;
                    }
                }
                else if (token == "^") res = pow(a, b);
                
                st.push(res);
            }
            else {
                // token is a number
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};
