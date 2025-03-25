class Solution {
  public:
    unordered_map<string, int> dp;
    
    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0; 
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];
        
        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            int leftTrue = solve(s, i, k - 1, true);
            int leftFalse = solve(s, i, k - 1, false);
            int rightTrue = solve(s, k + 1, j, true);
            int rightFalse = solve(s, k + 1, j, false);
            
            if (s[k] == '&') {
                if (isTrue) ways += leftTrue * rightTrue;
                else ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
            } 
            else if (s[k] == '|') {
                if (isTrue) ways += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
                else ways += leftFalse * rightFalse;
            } 
            else if (s[k] == '^') {
                if (isTrue) ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
                else ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
            }
        }
        
        return dp[key] = ways % 1003;  // Modulo to keep result within 32-bit integer
    }

    int countWays(string &s) {
        dp.clear();
        return solve(s, 0, s.size() - 1, true);
    }
};
