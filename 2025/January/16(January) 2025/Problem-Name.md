# Problem of the Day: Largest Subarray of 0's and 1's

## Problem Statement
Given an array `arr` consisting of 0s and 1s, find the length of the longest subarray with an equal number of 0s and 1s.

### Examples
#### Example 1:
**Input**:  
`arr = [1, 0, 1, 1, 1, 0, 0]`  

**Output**:  
`6`

**Explanation**:  
The subarray `arr[1...6]` contains three 0s and three 1s, making it the longest subarray with equal 0s and 1s.

#### Example 2:
**Input**:  
`arr = [0, 0, 1, 1, 0]`  

**Output**:  
`4`

**Explanation**:  
The subarrays `arr[0...3]` or `arr[1...4]` contain two 0s and two 1s, both having a length of 4.

#### Example 3:
**Input**:  
`arr = [0]`  

**Output**:  
`0`

**Explanation**:  
There is no subarray with an equal number of 0s and 1s.

### Constraints
- `1 <= arr.size() <= 10^5`
- `0 <= arr[i] <= 1`

---

## Approach
To solve this problem, the main idea is to replace all 0s in the array with -1s. This reduces the problem to finding the largest subarray with a sum of 0.

### Algorithm
1. Replace every `0` in the array with `-1`.
2. Use a prefix sum to calculate the cumulative sum as you iterate through the array.
3. Use a hash map to store the first occurrence of each prefix sum.
4. If a prefix sum is encountered again, calculate the length of the subarray between these two indices.
5. Keep track of the maximum length of such subarrays.

---

## Solution
Here’s the C++ implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int> &arr) {
        for (int &x : arr) {
            if (x == 0) x = -1;
        }

        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            if (prefixSum == 0) {
                maxLength = max(maxLength, i + 1);
            }

            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
            } else {
                prefixSumIndex[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num);
        }

        Solution obj;
        cout << obj.maxLen(arr) << endl;
    }

    return 0;
}
