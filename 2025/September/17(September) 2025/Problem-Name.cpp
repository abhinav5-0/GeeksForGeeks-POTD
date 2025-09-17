class Solution {
public:
    string decodedString(string &s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0'); // build the number
            }
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                k = 0;
                currentString = "";
            }
            else if (c == ']') {
                int repeat = countStack.top(); countStack.pop();
                string prevString = stringStack.top(); stringStack.pop();
                string expanded = "";
                for (int i = 0; i < repeat; i++) {
                    expanded += currentString;
                }
                currentString = prevString + expanded;
            }
            else {
                currentString += c;
            }
        }
        return currentString;
    }
};
