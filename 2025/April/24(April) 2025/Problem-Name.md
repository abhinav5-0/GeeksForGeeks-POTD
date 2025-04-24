# Problem: Unique Number III

## Difficulty: Medium

### Problem Statement:
Given an array of integers `arr[]`, every element appears **thrice** except for one element which appears **only once**. Find and return the element that appears only once.

### Input:
- An integer array `arr[]` where:
  - `1 <= arr.length <= 10^5`
  - `arr.length % 3 == 1`
  - `-10^9 <= arr[i] <= 10^9`

### Output:
- Return the integer that occurs only once.

### Example 1:
**Input:** `arr[] = [1, 10, 1, 1]`

**Output:** `10`

**Explanation:** All elements appear three times except `10`, which appears once.

### Example 2:
**Input:** `arr[] = [3, 2, 1, 34, 34, 1, 2, 34, 2, 1]`

**Output:** `3`

**Explanation:** Every number appears thrice except `3`.

### Constraints:
- Array size is always `mod 3 = 1`, ensuring exactly one element appears once.
- Values can be negative or positive integers.

### Optimized Bit Manipulation Solution:
We can use two integer variables `ones` and `twos` to track bits appearing once and twice. Any bit appearing three times is cleared from both.

```cpp
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int ones = 0, twos = 0;
        for (int num : arr) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};
```

### Time Complexity:
- **O(n)**, where `n` is the size of the array.

### Space Complexity:
- **O(1)**, using only two extra variables.

### Tags:
- Bit Manipulation
- Hashing
- Arrays
- Interview Question

