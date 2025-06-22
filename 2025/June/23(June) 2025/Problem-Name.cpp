class Solution {
  public:
    string minSum(vector<int> &arr) {
        // Sort the digits in ascending order
        sort(arr.begin(), arr.end());

        string num1 = "", num2 = "";

        // Distribute digits alternately to form two numbers
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0)
                num1 += to_string(arr[i]);
            else
                num2 += to_string(arr[i]);
        }

        // Add the two numbers represented by strings
        string result = addStrings(num1, num2);

        // Remove leading zeroes
        int i = 0;
        while (i < result.length() - 1 && result[i] == '0') i++;
        return result.substr(i);
    }

  private:
    // Helper function to add two numbers represented as strings
    string addStrings(string a, string b) {
        string res = "";
        int carry = 0, i = a.length() - 1, j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            res += (sum % 10) + '0';
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
