class Solution {
  public:
    bool isPalinSent(string &s) {
        string cleaned;
        
        // Step 1: Clean the string (keep only lowercase alphanumeric)
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        
        // Step 2: Check if the cleaned string is a palindrome
        int left = 0, right = cleaned.size() - 1;
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
