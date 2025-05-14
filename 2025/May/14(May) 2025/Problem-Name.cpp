class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string curr = "";
            int len = prev.size();
            for (int j = 0; j < len; ) {
                char digit = prev[j];
                int count = 0;
                while (j < len && prev[j] == digit) {
                    ++j;
                    ++count;
                }
                curr += to_string(count) + digit;
            }
            prev = curr;
        }
        return prev;
    }
};
