# Pair with Given Sum in a Sorted Array

### Difficulty: Easy

### Problem Statement:
You are given an integer `target` and a sorted array `arr[]`. Your task is to find the number of pairs in `arr[]` which sum up to `target`. Note that the pairs should consist of elements from distinct indices.

### Examples:

#### Example 1:
**Input:**
```plaintext
arr[] = [-1, 1, 5, 5, 7]
target = 6
```
**Output:**
```plaintext
3
```
**Explanation:**
There are 3 pairs which sum up to 6: {1, 5}, {1, 5}, and {-1, 7}.

#### Example 2:
**Input:**
```plaintext
arr[] = [1, 1, 1, 1]
target = 2
```
**Output:**
```plaintext
6
```
**Explanation:**
There are 6 pairs which sum up to 2: {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, and {1, 1}.

#### Example 3:
**Input:**
```plaintext
arr[] = [-1, 10, 10, 12, 15]
target = 125
```
**Output:**
```plaintext
0
```
**Explanation:**
There is no such pair which sums up to 125.

### Constraints:
- −105 ≤ target ≤ 105
-  2 ≤ arr.size() ≤ 105
- −105 ≤ arr[i] ≤ 105

### Approach:

#### **Two-Pointer Technique**:
1. Start with two pointers:
   - `left` pointing to the beginning of the array.
   - `right` pointing to the end of the array.
2. Adjust the pointers based on the sum of elements:
   - If the sum equals the `target`, calculate the number of pairs and move the pointers inward.
   - If the sum is less than the `target`, increment `left`.
   - If the sum is greater than the `target`, decrement `right`.
3. Consider duplicate elements:
   - When encountering duplicates on either end, count their frequency and calculate the combinations of pairs formed.

### Implementation:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int count = 0;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                if (arr[left] == arr[right]) {
                    int n = right - left + 1;
                    count += (n * (n - 1)) / 2;
                    break;
                } else {
                    int countLeft = 1, countRight = 1;

                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        left++;
                        countLeft++;
                    }

                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        right--;
                        countRight++;
                    }

                    count += countLeft * countRight;
                    left++;
                    right--;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return count;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int target;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> target;
        cin.ignore();

        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
```

### Complexity Analysis:
- **Time Complexity:** \(O(n)\)
  - Each pointer moves at most \(n\) times.
- **Space Complexity:** \(O(1)\)
  - No additional space is required apart from the input array.

### Edge Cases:
1. All elements are the same, e.g., `[1, 1, 1, 1]` with `target = 2`.
2. No pairs exist that sum up to the `target`.
3. Large inputs with maximum constraints.

### Notes:
- Ensure that duplicate elements are handled correctly to avoid overcounting pairs.
- The input array is guaranteed to be sorted, which simplifies the implementation of the two-pointer technique.
