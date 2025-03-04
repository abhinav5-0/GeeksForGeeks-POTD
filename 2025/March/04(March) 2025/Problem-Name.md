# Longest Increasing Subsequence (LIS)

## Problem Statement
Given an array `arr[]` of non-negative integers, the task is to find the length of the **Longest Strictly Increasing Subsequence (LIS)**.

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

### Example Inputs & Outputs

#### Example 1
**Input:**
```cpp
arr[] = [5, 8, 3, 7, 9, 1]
```
**Output:**
```
3
```
**Explanation:** The longest strictly increasing subsequence could be `[5, 7, 9]`, which has a length of `3`.

#### Example 2
**Input:**
```cpp
arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
```
**Output:**
```
6
```
**Explanation:** One possible longest strictly increasing subsequence is `[0, 2, 6, 9, 13, 15]`.

## Constraints
- `1 ≤ arr.size() ≤ 1000`
- `0 ≤ arr[i] ≤ 10^6`

## Approaches

### 1. Naïve Approach (O(n²) using Dynamic Programming)
- Use a `dp` array where `dp[i]` stores the LIS ending at index `i`.
- Traverse each `i` and check all previous elements `j` (`j < i`).
- If `arr[i] > arr[j]`, update `dp[i] = max(dp[i], dp[j] + 1)`.
- Track the maximum length found.

### 2. Optimized Approach (O(n log n) using Binary Search + DP)
- Use **Patience Sorting Technique** with **Binary Search**.
- Maintain a `temp` array where elements are sorted.
- Use `lower_bound()` to find the position where `arr[i]` should be placed.
- If found, replace it; otherwise, append `arr[i]` to `temp`.
- The size of `temp` gives the length of LIS.

## Implementation

### C++ Code
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find length of LIS using Dynamic Programming O(n^2)
    int lis(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1); // dp[i] stores the LIS ending at index i
        
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
    
    // Optimized LIS using Binary Search + DP O(n log n)
    int lisOptimized(vector<int>& arr) {
        vector<int> temp;
        for (int num : arr) {
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if (it == temp.end()) {
                temp.push_back(num);
            } else {
                *it = num;
            }
        }
        return temp.size();
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lisOptimized(arr) << endl; // Using optimized approach
        cout << "~" << endl;
    }

    return 0;
}
```

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
|----------|----------------|------------------|
| DP (O(n²)) | O(n²) | O(n) |
| Binary Search + DP (O(n log n)) | O(n log n) | O(n) |

## Summary
- **O(n²) approach:** Uses a `dp` array to compute LIS for every index.
- **O(n log n) approach:** Uses a sorted array and binary search to build LIS efficiently.

🚀 The optimized approach is preferred for large inputs! 🚀

