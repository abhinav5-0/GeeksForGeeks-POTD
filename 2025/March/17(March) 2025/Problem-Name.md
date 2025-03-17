#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Solution class to determine if a subset with a given sum exists in an array.
 */
class Solution {
  public:
    /**
     * @brief Checks if there is a subset with sum equal to the given sum.
     *
     * @param arr The input array of positive integers.
     * @param sum The target sum to check.
     * @return true if a subset exists with the given sum, otherwise false.
     */
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // If sum is 0, then subset always exists (empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Fill the dp table using Bottom-Up Dynamic Programming
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};

/**
 * @brief Main function to handle multiple test cases.
 */
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
