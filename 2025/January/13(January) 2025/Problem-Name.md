# Container With Most Water

## Problem Statement
Given an array `arr[]` of non-negative integers, where each element `arr[i]` represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.

### Constraints
- `1 <= arr.size() <= 10^5`
- `1 <= arr[i] <= 10^4`

### Examples
#### Example 1:
Input: `arr[] = [1, 5, 4, 3]`  
Output: `6`  
Explanation: 5 and 3 are 2 distance apart. Height = min(5, 3) = 3. Total area = `3 * 2 = 6`.

#### Example 2:
Input: `arr[] = [3, 1, 2, 4, 5]`  
Output: `12`  
Explanation: 5 and 3 are 4 distance apart. Height = min(5, 3) = 3. Total area = `4 * 3 = 12`.

#### Example 3:
Input: `arr[] = [2, 1, 8, 6, 4, 6, 5, 5]`  
Output: `25`  
Explanation: 8 and 5 are 5 distance apart. Height = min(8, 5) = 5. Total area = `5 * 5 = 25`.

## Solution
The problem is solved using the **Two Pointers Technique** to achieve optimal time complexity.

### Approach
1. **Initialize Pointers**: Place one pointer at the beginning (`left`) and one at the end (`right`) of the array.
2. **Calculate Area**: Use the formula:
   
   ```
   Area = min(arr[left], arr[right]) * (right - left)
   ```

3. **Update Maximum Area**: Keep track of the largest area encountered.
4. **Move Pointers**:
   - If `arr[left] < arr[right]`, increment `left`.
   - Else, decrement `right`.
5. **Repeat**: Continue until the two pointers meet.

### Complexity
- **Time Complexity**: `O(n)` — Each element is processed at most once.
- **Space Complexity**: `O(1)` — No additional space is used.

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int currentArea = height * width;

            maxArea = max(maxArea, currentArea);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
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
        int res = ob.maxWater(arr);

        cout << res << endl;
    }
    return 0;
}
```

## Usage
1. Compile the code using a C++ compiler.
2. Provide the input as:
   - First line: Number of test cases `t`.
   - Following lines: Space-separated integers representing the array for each test case.

### Example Input:
```
2
1 5 4 3
3 1 2 4 5
```
### Example Output:
```
6
12
