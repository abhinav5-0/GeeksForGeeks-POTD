# Product Array Puzzle

## Problem Statement
Given an array `arr[]`, construct a product array `res[]` where each element in `res[i]` is the product of all elements in `arr[]` except `arr[i]`. Return the resultant array `res[]`.

### Constraints
- Array size ranges from 2 to 100,000.
- Each element in the array is between -100 and 100.
- All elements in `res[]` are within the 32-bit integer range.

### Examples

#### Example 1:
**Input:**
```plaintext
arr[] = [10, 3, 5, 6, 2]
```
**Output:**
```plaintext
[180, 600, 360, 300, 900]
```
**Explanation:**
For each index `i`, the product of all elements except `arr[i]` is calculated as follows:
- res[0] = 3 \* 5 \* 6 \* 2 = 180
- res[1] = 10 \* 5 \* 6 \* 2 = 600
- res[2] = 10 \* 3 \* 6 \* 2 = 360
- res[3] = 10 \* 3 \* 5 \* 2 = 300
- res[4] = 10 \* 3 \* 5 \* 6 = 900

#### Example 2:
**Input:**
```plaintext
arr[] = [12, 0]
```
**Output:**
```plaintext
[0, 12]
```
**Explanation:**
- res[0] = 0 (as one element is 0)
- res[1] = 12 (the product of the non-zero element)

---

## Approach

### Logic
1. **Prefix Product:** Compute cumulative products of elements to the left of each index.
2. **Suffix Product:** Compute cumulative products of elements to the right of each index.
3. **Result:** Multiply the prefix and suffix products to get the result for each index.

### Optimization
- Use a single array to store prefix products.
- Maintain a running suffix product during a backward pass to save space.

---

## Implementation

### C++ Code
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);

        // Calculate prefix products
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * arr[i - 1];
        }

        // Calculate suffix products and update result
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= arr[i];
        }

        return res;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity:**
  - Prefix computation: \(O(n)\)
  - Suffix computation: \(O(n)\)
  - Total: \(O(n)\)

- **Space Complexity:**
  - Optimized solution uses \(O(1)\) extra space (excluding result array).

---

## Example Execution

**Input:**
```plaintext
arr[] = [10, 3, 5, 6, 2]
```

**Execution Steps:**
1. Calculate prefix products:
   ```plaintext
   res = [1, 10, 30, 150, 900]
   ```
2. Calculate suffix products and update:
   ```plaintext
   suffix = [180, 60, 12, 2, 1]
   res = [180, 600, 360, 300, 900]
   ```

**Output:**
```plaintext
[180, 600, 360, 300, 900]
