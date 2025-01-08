# Count the Number of Possible Triangles

## Problem Statement
Given an integer array `arr[]`, find the number of triangles that can be formed using three different elements of the array as the lengths of the sides of a triangle. 

A triangle is valid if the sum of any two sides is greater than the third side.

---

### Examples

#### Example 1:
**Input:**  
`arr[] = [4, 6, 3, 7]`  
**Output:**  
`3`  

**Explanation:**  
Valid triangles are:  
- `[3, 4, 6]`
- `[4, 6, 7]`
- `[3, 6, 7]`

#### Example 2:
**Input:**  
`arr[] = [10, 21, 22, 100, 101, 200, 300]`  
**Output:**  
`6`  

**Explanation:**  
Valid triangles are:  
- `[10, 21, 22]`
- `[21, 100, 101]`
- `[22, 100, 101]`
- `[10, 100, 101]`
- `[100, 101, 200]`
- `[101, 200, 300]`

#### Example 3:
**Input:**  
`arr[] = [1, 2, 3]`  
**Output:**  
`0`  

**Explanation:**  
No valid triangles can be formed.

---

### Constraints
- \(3 \leq \text{arr.size()} \leq 10^3\)
- \(1 \leq \text{arr[i]} \leq 10^5\)

---

## Approach

### Steps:
1. **Sort the Array:** Sort the array in ascending order.  
   This helps in simplifying the triangle inequality check.

2. **Three-Pointer Technique:**
   - Use an outer loop to fix the largest side, `arr[k]`.
   - Use two pointers:
     - \(i = 0\): Start of the array.
     - \(j = k-1\): Just before the largest side.
   - Check:
     - If `arr[i] + arr[j] > arr[k]`, then all pairs between `i` and `j` are valid.
       - Add `(j - i)` to the count.
       - Decrease `j`.
     - Else, increase `i`.

3. **Return the Count:** After iterating through all possible combinations, return the count of valid triangles.

---

### Algorithm

1. **Sort** the array in ascending order.
2. Initialize `count = 0`.
3. Loop from `k = n-1` down to `2`:
   - Initialize `i = 0` and `j = k-1`.
   - While `i < j`:
     - If `arr[i] + arr[j] > arr[k]`:
       - Add `(j - i)` to `count`.
       - Decrease `j`.
     - Else:
       - Increase `i`.
4. Return `count`.

---

## Code Implementation

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count the number of possible triangles
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;

        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    count += (j - i); // Add all pairs between i and j
                    --j;
                } else {
                    ++i;
                }
            }
        }
        return count;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int n, x;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            arr.push_back(x);
        }
        Solution obj;
        cout << obj.countTriangles(arr) << endl;
    }
    return 0;
}
```

## Complexity

### Time Complexity:
- **Sorting:** \( O(nlog n) \)
- **Two-pointer traversal:** \( O(n^2) \) in the worst case.  
**Total:** \( O(n^2) \).

### Space Complexity:
- \( O(1) \): Sorting is done in-place, and no extra data structures are used.

---

## Edge Cases

1. **Small Array:**  
   If the array size is less than 3, return `0` (no triangles possible).

2. **All Elements Equal:**  
   Example: `arr[] = [1, 1, 1, 1]`.  
   Valid triangles can still be formed.

3. **Large Gaps Between Elements:**  
   Example: `arr[] = [1, 2, 10]`.  
   No valid triangles can be formed.

---

## Additional Notes

- This approach efficiently handles arrays with sizes up to the maximum constraint (\( n = 1000 \)).
- Sorting ensures that checking the triangle inequality becomes straightforward.
