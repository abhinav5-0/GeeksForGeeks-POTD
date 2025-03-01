class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int> numStack;
        string currStr = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // Constructing the number
            } else if (c == '[') {
                numStack.push(num);  // Store the repeat count
                strStack.push(currStr);  // Store the current string
                num = 0;
                currStr = "";
            } else if (c == ']') {
                int repeatCount = numStack.top(); numStack.pop();
                string temp = currStr;
                for (int i = 1; i < repeatCount; i++) {
                    currStr += temp;
                }
                currStr = strStack.top() + currStr;  // Concatenate with the previous stored string
                strStack.pop();
            } else {
                currStr += c;  // Build the current string
            }
        }
        return currStr;
    }
};
