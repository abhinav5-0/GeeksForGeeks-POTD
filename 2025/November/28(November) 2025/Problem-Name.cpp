class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;

        // compute XOR of 1..n
        int X;
        if (n % 4 == 0) X = n;
        else if (n % 4 == 1) X = 1;
        else if (n % 4 == 2) X = n + 1;
        else X = 0;

        // if XOR is already n, return all numbers
        if (X == n) {
            ans.reserve(n);
            for (int i = 1; i <= n; i++) ans.push_back(i);
            return ans;
        }

        // else find the element to remove
        int missing = X ^ n;   // the required element to delete

        // build result excluding the missing one
        ans.reserve(n - 1);
        for (int i = 1; i <= n; i++) {
            if (i != missing) ans.push_back(i);
        }
        return ans;
    }
};
