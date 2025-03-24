# Matrix Chain Multiplication

## Problem Statement
Given an array `arr[]` representing the dimensions of a sequence of matrices, where the `i`th matrix has the dimensions `(arr[i-1] x arr[i])` for `i >= 1`, find the most efficient way to multiply these matrices together. The goal is to minimize the number of scalar multiplications required.

## Approach
We use **Dynamic Programming (Memoization - Top-Down Approach)** to optimize the recursive solution by storing previously computed results.

## Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return matrixChainMemo(arr, 1, n - 1, dp);
    }

  private:
    int matrixChainMemo(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return 0; // Base case: No multiplication needed
        if (dp[i][j] != -1) return dp[i][j];
        
        int minCost = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost = matrixChainMemo(arr, i, k, dp) +
                       matrixChainMemo(arr, k + 1, j, dp) +
                       (arr[i - 1] * arr[k] * arr[j]);
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl;
    }

    return 0;
}
```

## Explanation
1. **Recursive Approach with Memoization:**  
   - We define a helper function `matrixChainMemo(arr, i, j, dp)`, where:
     - `i` is the starting index of the matrix sequence.
     - `j` is the ending index.
     - `dp[i][j]` stores the minimum cost for multiplying matrices from `i` to `j`.
   - We use a `for` loop to try different partitions `k` between `i` and `j`, computing the cost recursively.
   - The final result is stored in `dp[1][n-1]`.

2. **Time Complexity:**  
   - **O(n³)** due to three nested loops (one for recursion and two for matrix multiplications).
   - **Space Complexity:** O(n²) for memoization.

This approach significantly reduces redundant calculations by storing intermediate results. 🚀
