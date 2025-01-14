# Longest Subarray with Sum K

### Problem Statement
Given an array `arr[]` containing integers and an integer `k`, the task is to find the length of the longest subarray where the sum of its elements equals the given value `k`. If no such subarray exists, return `0`.

---

### Examples

#### Example 1:
**Input:**
```
arr[] = [10, 5, 2, 7, 1, -10], k = 15
```
**Output:**
```
6
```
**Explanation:**
Subarrays with sum = 15 are:
- [5, 2, 7, 1]
- [10, 5]
- [10, 5, 2, 7, 1, -10]
The length of the longest subarray is `6`.

#### Example 2:
**Input:**
```
arr[] = [-5, 8, -14, 2, 4, 12], k = -5
```
**Output:**
```
5
```
**Explanation:**
The only subarray with sum = -5 is:
- [-5, 8, -14, 2, 4] of length `5`.

#### Example 3:
**Input:**
```
arr[] = [10, -10, 20, 30], k = 5
```
**Output:**
```
0
```
**Explanation:**
No subarray with sum = 5 is present in `arr[]`.

---

### Constraints
- `1 \leq arr.size() \leq 10^5`
- `-10^4 \leq arr[i] \leq 10^4`
- `-10^9 \leq k \leq 10^9`

---

### Approach
1. Use a **hash map** to store prefix sums and their earliest occurrences.
2. Iterate through the array and compute the cumulative sum (`currentSum`).
3. For each element:
   - Check if `currentSum == k`, update the maximum length.
   - Check if `currentSum - k` exists in the hash map. If yes, compute the subarray length and update the maximum length.
   - Store `currentSum` in the hash map if it is not already present.
4. Return the maximum length of the subarray.

---

### Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap;
        int currentSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];

            if (currentSum == k) {
                maxLength = i + 1;
            }

            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[currentSum - k]);
            }

            if (prefixSumMap.find(currentSum) == prefixSumMap.end()) {
                prefixSumMap[currentSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine);
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore();

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
    }

    return 0;
}
```

---

### Complexity Analysis
- **Time Complexity:** `O(n)`
  - Each element is processed once.
  - Hash map operations (insert and lookup) are `O(1)` on average.
- **Space Complexity:** `O(n)`
  - Hash map stores at most `n` elements.

---

### Edge Cases
1. Array with all positive numbers.
2. Array with negative numbers.
3. No subarray with the given sum `k`.
4. Large values of `k` and large input size.

---
