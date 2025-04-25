# Majority Element Problem

## Problem Statement
Given an array `arr[]`, find the majority element in the array. If no majority element exists, return -1.

**Definition:** A majority element in an array is an element that appears **strictly more than** `arr.size() / 2` times.

## Examples

### Example 1
**Input:** `arr[] = [1, 1, 2, 1, 3, 5, 1]`  
**Output:** `1`  
**Explanation:** Element `1` appears 4 times, which is more than 7/2 = 3.5.

### Example 2
**Input:** `arr[] = [7]`  
**Output:** `7`  
**Explanation:** Element `7` appears once and the array has only one element.

### Example 3
**Input:** `arr[] = [2, 13]`  
**Output:** `-1`  
**Explanation:** No element appears more than 2/2 = 1 time.

## Constraints
- 1 <= `arr.size()` <= 10^5
- 0 <= `arr[i]` <= 10^5

## Solution Approach
The optimal solution uses the **Boyer-Moore Voting Algorithm**:

### Step 1: Find a Candidate
- Initialize `count = 0`, `candidate = None`
- Traverse the array:
  - If `count == 0`, set `candidate = current element`
  - If current element == candidate, increment `count`
  - Else, decrement `count`

### Step 2: Verify the Candidate
- Count the frequency of `candidate` in the array
- If it appears more than `arr.size() / 2` times, return it
- Else, return `-1`

## Time and Space Complexity
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## C++ Implementation
```cpp
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0, candidate = -1;

        // Step 1: Find candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify candidate
        count = 0;
        for (int num : arr) {
            if (num == candidate) count++;
        }

        return (count > arr.size() / 2) ? candidate : -1;
    }
};
```

