class Solution {
public:
    // Helper to check if a string has leading zeros (invalid case)
    bool hasLeadingZero(const string& str) {
        return str.size() > 1 && str[0] == '0';
    }

    // Add two large numbers represented as strings
    string stringAdd(const string& a, const string& b) {
        string result = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // Recursive check
    bool check(const string& s, int start, const string& first, const string& second) {
        string sum = stringAdd(first, second);
        int sumLen = sum.length();

        if (start + sumLen > s.size()) return false;
        if (s.substr(start, sumLen) != sum) return false;
        if (start + sumLen == s.size()) return true;

        return check(s, start + sumLen, second, sum);
    }

    bool isSumString(string &s) {
        int n = s.size();

        // Try all possible first and second splits
        for (int i = 1; i < n; i++) {
            for (int j = 1; i + j < n; j++) {
                string first = s.substr(0, i);
                string second = s.substr(i, j);

                // Skip if any number has leading zeros
                if (hasLeadingZero(first) || hasLeadingZero(second)) continue;

                if (check(s, i + j, first, second)) return true;
            }
        }
        return false;
    }
};
