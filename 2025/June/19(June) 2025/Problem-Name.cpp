class Solution {
  public:
    string caseSort(string& s) {
        string lower, upper;

        // Step 1: Separate characters
        for (char ch : s) {
            if (islower(ch)) lower.push_back(ch);
            else upper.push_back(ch);
        }

        // Step 2: Sort them
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // Step 3: Replace according to original case
        int li = 0, ui = 0;
        string result = s;

        for (int i = 0; i < s.length(); ++i) {
            if (islower(s[i])) {
                result[i] = lower[li++];
            } else {
                result[i] = upper[ui++];
            }
        }

        return result;
    }
};
