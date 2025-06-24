class Solution {
public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int to_keep = n - k;
        string stack;

        for (char c : s) {
            while (!stack.empty() && k > 0 && stack.back() < c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }

        // We might have pushed more than needed
        stack.resize(to_keep);
        return stack;
    }
};
