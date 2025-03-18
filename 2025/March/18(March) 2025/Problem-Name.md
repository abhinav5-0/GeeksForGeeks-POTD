
**Explanation:** This array can never be partitioned into two such parts.

### Constraints:
- `1 ≤ arr.size ≤ 100`
- `1 ≤ arr[i] ≤ 200`

## Approach

### Key Observations:
1. If the total sum of the array is odd, it’s impossible to partition the array into two equal subsets. Therefore, we first check if the total sum is even.
2. If the total sum is even, we aim to find if there exists a subset whose sum is exactly half of the total sum. This problem is equivalent to the **Subset Sum Problem**.

### Dynamic Programming (DP):
We can use a dynamic programming approach to solve this problem. We will:
1. Calculate the total sum of the array.
2. If the total sum is odd, return `false`.
3. Otherwise, calculate `target = total / 2` and check if a subset sum of `target` is possible.
4. Use a DP array to keep track of possible sums.

### Algorithm:
1. Calculate the sum of the array elements.
2. If the sum is odd, return `false`.
3. Create a DP array of size `target + 1` and initialize `dp[0] = true`.
4. Iterate through each element in the array and update the DP array.
5. If `dp[target]` is `true`, return `true`. Otherwise, return `false`.

## Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // If the total sum is odd, partition is not possible
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        
        // Create a DP array where dp[i] will be true if a subset with sum i is possible
        vector<bool> dp(target + 1, false);
        dp[0] = true;  // Sum 0 is always possible (empty set)
        
        // Iterate through each element in the array
        for (int num : arr) {
            // Traverse the dp array backward
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        // The answer is true if dp[target] is true
        return dp[target];
    }
};

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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
