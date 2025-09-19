class Solution {
public:
    int minParentheses(string& s) {
        int open = 0;  // count of unmatched '('
        int add = 0;   // count of unmatched ')'
        
        for (char c : s) {
            if (c == '(') {
                open++;
            } else { // c == ')'
                if (open > 0) {
                    open--; // match with a '('
                } else {
                    add++; // need to insert '('
                }
            }
        }
        
        // add (unmatched ')') + open (unmatched '(')
        return add + open;
    }
};
