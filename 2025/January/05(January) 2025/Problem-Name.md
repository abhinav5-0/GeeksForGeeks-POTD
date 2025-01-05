# Count Pairs with Sum Less Than Target

## Problem Statement
Given an array `arr[]` and an integer `target`, find the number of pairs in the array whose sum is strictly less than the target.

---

## Examples
### Example 1:
**Input:**
```
arr[] = [7, 2, 5, 3]
target = 8
```
**Output:**
```
2
```
**Explanation:**
There are 2 pairs with sum less than 8: `(2, 5)` and `(2, 3)`.

---

### Example 2:
**Input:**
```
arr[] = [5, 2, 3, 2, 4, 1]
target = 5
```
**Output:**
```
4
```
**Explanation:**
There are 4 pairs with sum less than 5: `(2, 2)`, `(2, 1)`, `(3, 1)`, and `(2, 1)`.

---

### Example 3:
**Input:**
```
arr[] = [2, 1, 8, 3, 4, 7, 6, 5]
target = 7
```
**Output:**
```
6
```
**Explanation:**
There are 6 pairs whose sum is less than 7: `(2, 1)`, `(2, 3)`, `(2, 4)`, `(1, 3)`, `(1, 4)`, and `(1, 5)`.

---

## Constraints
- `1 <= arr.size() <= 10^5`
- `0 <= arr[i] <= 10^4`
- `1 <= target <= 10^4`

---

## Algorithm
1. **Sort the Array:** This ensures pairs can be evaluated efficiently in increasing order.
2. **Two Pointer Approach:**
   - Use two pointers (`left` at the start, `right` at the end).
   - If the sum of `arr[left] + arr[right]` is less than the target:
     - Count all pairs between `left` and `right` (`right - left`).
     - Move `left` forward to evaluate the next element.
   - Otherwise, move `right` backward to reduce the sum.
3. **Repeat Until Pointers Meet:** Stop when `left >= right`.

---

## Implementation
### C++ Code
```cpp
class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int count = 0;
        int left = 0, right = arr.size() - 1;
        
        while (left < right) {
            if (arr[left] + arr[right] < target) {
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        
        return count;
    }
};
```

---

## Complexity
- **Time Complexity:**
  - Sorting: `O(n log n)`
  - Two-pointer traversal: `O(n)`
  - **Total:** `O(n log n)`

- **Space Complexity:** `O(1)` (excluding input storage).

---

## Example Walkthrough
### Input:
```
arr = [7, 2, 5, 3], target = 8
```
**Steps:**
1. Sort the array: `arr = [2, 3, 5, 7]`
2. Initialize pointers: `left = 0, right = 3`
3. Steps:
   - `arr[left] + arr[right] = 2 + 7 = 9` (>= 8), decrement `right`.
   - `arr[left] + arr[right] = 2 + 5 = 7` (< 8), add `right - left = 2`, increment `left`.
   - `arr[left] + arr[right] = 3 + 5 = 8` (>= 8), decrement `right`.
4. **Count:** `2`

**Output:**
```
2
