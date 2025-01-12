# Trapping Rain Water Problem

## Problem Description
Given an array `arr[]` representing the height of blocks where the width of each block is `1`, calculate how much water can be trapped between the blocks during the rainy season.

---

### Example Input and Output

#### Example 1:
**Input:**  
`arr[] = [3, 0, 1, 0, 4, 0, 2]`  
**Output:**  
`10`  

**Explanation:**  
Total water trapped = `0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units`.

---

#### Example 2:
**Input:**  
`arr[] = [2, 1, 5, 3, 1, 0, 4]`  
**Output:**  
`9`  

**Explanation:**  
Total water trapped = `0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units`.

---

#### Example 3:
**Input:**  
`arr[] = [1, 2, 3, 4]`  
**Output:**  
`0`  

**Explanation:**  
No water is trapped because there are no height bounds.

---

### Constraints
- \(1 < \text{arr.size()} < 10^5\)
- \(0 < \text{arr[i]} < 10^3\)

---

## Solution Approach

### **Optimal Two-Pointer Solution**

1. **Two Pointers:**
   - Initialize two pointers `left` (start) and `right` (end of the array).
   - Maintain two variables, `leftMax` and `rightMax`, to track the maximum heights seen so far from the left and right sides.

2. **Logic:**
   - Compare the heights at `left` and `right`.
   - If `arr[left] < arr[right]`:
     - Calculate water trapped at `left` as `leftMax - arr[left]`.
     - Update `leftMax` and move the `left` pointer inward.
   - Otherwise:
     - Calculate water trapped at `right` as `rightMax - arr[right]`.
     - Update `rightMax` and move the `right` pointer inward.

3. **Continue until `left` meets `right`** and accumulate the total water.

---

### **Time Complexity:**  
- **\(O(n)\):** Single pass through the array.

### **Space Complexity:**  
- **\(O(1)\):** No extra arrays required.

---

## Code Implementation

### **C++ Code:**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0, totalWater = 0;

        while (left <= right) {
            if (arr[left] < arr[right]) {
                if (arr[left] >= leftMax)
                    leftMax = arr[left];
                else
                    totalWater += leftMax - arr[left];
                left++;
            } else {
                if (arr[right] >= rightMax)
                    rightMax = arr[right];
                else
                    totalWater += rightMax - arr[right];
                right--;
            }
        }
        return totalWater;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read the input array
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
