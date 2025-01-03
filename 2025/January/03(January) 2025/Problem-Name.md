# Count Subarrays with Given XOR

## Problem Statement
Given an array of integers `arr[]` and a number `k`, count the number of subarrays having XOR of their elements as `k`.

### Examples:

#### Example 1
Input:  
```
arr[] = [4, 2, 2, 6, 4]
k = 6
```
Output:  
```
4
```
Explanation:  
The subarrays having XOR of their elements as `6` are:
- [4, 2]
- [4, 2, 2, 6, 4]
- [2, 2, 6]
- [6]

#### Example 2
Input:  
```
arr[] = [5, 6, 7, 8, 9]
k = 5
```
Output:  
```
2
```
Explanation:  
The subarrays having XOR of their elements as `5` are:
- [5]
- [5, 6, 7, 8, 9]

#### Example 3
Input:  
```
arr[] = [1, 1, 1, 1]
k = 0
```
Output:  
```
4
```
Explanation:  
The subarrays are:
- [1, 1]
- [1, 1]
- [1, 1]
- [1, 1, 1, 1]

## Constraints:
- `1 ≤ arr.size() ≤ 10^5`
- `0 ≤ arr[i] ≤ 10^5`
- `0 ≤ k ≤ 10^5`

---

## Approach
The problem can be solved efficiently using a hash map to store frequencies of XOR values encountered so far. This approach works in O(n) time complexity.

### Steps:
1. Use a variable `xorSum` to keep track of the cumulative XOR as we traverse the array.
2. Use a hash map `freq` to store the frequency of XOR values encountered so far.
3. For each element in the array:
   - Calculate `xorSum`.
   - If `xorSum ^ k` exists in the hash map, increment the result count by the frequency of `xorSum ^ k`.
   - Update the hash map with the current `xorSum`.
4. Return the total count of subarrays.

---

## Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> freq; // To store frequency of XOR values
        int xorSum = 0;              // Cumulative XOR
        long count = 0;              // Count of subarrays

        // Initialize the map to handle cases where xorSum itself equals k
        freq[0] = 1;

        for (int num : arr) {
            xorSum ^= num; // Update cumulative XOR

            // Check if xorSum ^ k exists in the map
            if (freq.find(xorSum ^ k) != freq.end()) {
                count += freq[xorSum ^ k];
            }

            // Update the frequency map
            freq[xorSum]++;
        }

        return count;
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Key Points:
1. **Time Complexity**: `O(n)`, as each element is processed once.
2. **Space Complexity**: `O(n)`, for storing the XOR frequencies in the hash map.
3. **Edge Cases**: Arrays where all elements are the same, `k = 0`, and very large arrays.

---

## Usage
To run the code:
1. Compile using a C++ compiler.
2. Provide test cases as input. Each test case consists of an array followed by the value of `k`.

Example Input:
```
2
4 2 2 6 4
6
5 6 7 8 9
5
```

Example Output:
```
4
2
~
```

---

## License
This project is licensed under the MIT License.
