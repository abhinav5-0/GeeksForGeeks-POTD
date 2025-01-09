# Subarray Sum Problem

### Problem Statement
Given an array `arr[]` containing only non-negative integers, the task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value `target`. Return the 1-based indices of the leftmost and rightmost elements of this subarray. If no such subarray exists, return `[-1]`.

### Examples

#### Example 1
**Input:**
```
arr[] = [1, 2, 3, 7, 5], target = 12
```
**Output:**
```
[2, 4]
```
**Explanation:**
The sum of elements from 2nd to 4th position is 12.

#### Example 2
**Input:**
```
arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
```
**Output:**
```
[1, 5]
```
**Explanation:**
The sum of elements from 1st to 5th position is 15.

#### Example 3
**Input:**
```
arr[] = [5, 3, 4], target = 2
```
**Output:**
```
[-1]
```
**Explanation:**
There is no subarray with sum 2.

### Constraints
- \(1 \leq \text{arr.size()} \leq 10^6\)
- \(0 \leq \text{arr}[i] \leq 10^3\)
- \(0 \leq \text{target} \leq 10^9\)

### Solution
Below is the C++ implementation of the solution using the sliding window approach:

```cpp
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int start = 0, current_sum = 0;

        for (int end = 0; end < n; end++) {
            // Add the current element to the sum
            current_sum += arr[end];

            // If current_sum exceeds the target, remove elements from the start
            while (current_sum > target && start <= end) {
                current_sum -= arr[start];
                start++;
            }

            // Check if the current_sum equals the target
            if (current_sum == target) {
                return {start + 1, end + 1}; // Return 1-based indices
            }
        }

        // If no subarray is found
        return {-1};
    }
};
```

### Explanation

1. **Sliding Window Technique**:
   - Start with `start = 0` and `current_sum = 0`.
   - Iterate through the array using `end`.
   - Add the current element `arr[end]` to `current_sum`.

2. **Shrinking the Window**:
   - If `current_sum > target`, remove elements from the `start` of the window until `current_sum <= target`.

3. **Checking for Target**:
   - If `current_sum == target`, return the 1-based indices `{start + 1, end + 1}`.

4. **No Match Case**:
   - If the loop completes without finding a subarray, return `{-1}`.

### Complexity

- **Time Complexity**: \(O(n)\), as each element is added and removed from the sum at most once.
- **Space Complexity**: \(O(1)\), as no extra space is used apart from variables.
