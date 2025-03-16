# Minimum Jumps Problem

## Problem Statement
You are given an array `arr[]` of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.

- If `arr[i] = 3`, you can jump to index `i + 1`, `i + 2`, or `i + 3` from position `i`.
- If `arr[i] = 0`, you cannot jump forward from that position.

Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

**Note:** Return `-1` if you can't reach the end of the array.

## Examples

### Example 1:
**Input:** `arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]`  
**Output:** `3`  
**Explanation:**
- First jump from 1st element to 2nd element with value 3.
- From here we jump to 5th element with value 9.
- From here we jump to the last element.

### Example 2:
**Input:** `arr = [1, 4, 3, 2, 6, 7]`  
**Output:** `2`  
**Explanation:**
- First jump from the 1st to 2nd element.
- Then jump to the last element.

### Example 3:
**Input:** `arr = [0, 10, 20]`  
**Output:** `-1`  
**Explanation:** We cannot go anywhere from the 1st element.

## Constraints:
- `2 ≤ arr.size() ≤ 10^4`
- `0 ≤ arr[i] ≤ 10^4`

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 1) return 0;
        if (arr[0] == 0) return -1;
        
        int maxReach = arr[0], steps = arr[0], jumps = 1;
        
        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;
            
            maxReach = max(maxReach, i + arr[i]);
            steps--;
            
            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1;
                steps = maxReach - i;
            }
        }
        
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}
```

## Explanation

1. **Edge Cases Handling:**
   - If the array has only one element, no jumps are needed (`return 0`).
   - If the first element is `0`, we can't move forward (`return -1`).

2. **Variable Initialization:**
   - `maxReach`: The farthest index that can be reached.
   - `steps`: The number of steps remaining within the current jump.
   - `jumps`: The total number of jumps taken.

3. **Traversal Logic:**
   - Iterate through the array.
   - Update `maxReach` at each step.
   - Decrease `steps`, and if `steps` becomes zero, increase `jumps` and reset `steps` based on `maxReach`.

4. **Failure Condition:**
   - If the current index `i` is greater than or equal to `maxReach`, return `-1`.

**Time Complexity:** `O(n)`, making it efficient for large inputs. 🚀
