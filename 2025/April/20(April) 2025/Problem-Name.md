# Problem Statement: Find Only Repetitive Element from 1 to n-1

**Difficulty:** Easy  
**Accuracy:** 59.22%  
**Submissions:** 13K+  
**Points:** 2

## Problem Description
Given an array `arr[]` of size `n`, filled with numbers from `1` to `n-1` in random order. The array has only one repetitive element. Your task is to find the repetitive element.

### Note:
- It is guaranteed that there is a repeating element present in the array.

## Constraints
- 2 ≤ arr.size() ≤ 10<sup>5</sup>
- 1 ≤ arr[i] ≤ n-1

## Input Format
- A single line containing space-separated integers representing the array elements.

## Output Format
- A single integer representing the only repeating element in the array.

## Examples
### Example 1:
**Input:**
```
1 3 2 3 4
```
**Output:**
```
3
```
**Explanation:**
The number 3 is the only repeating element.

### Example 2:
**Input:**
```
1 5 1 2 3 4
```
**Output:**
```
1
```
**Explanation:**
The number 1 is the only repeating element.

### Example 3:
**Input:**
```
1 1
```
**Output:**
```
1
```
**Explanation:**
The array is of size 2 with both elements being 1, making 1 the repeating element.

## Solution Approach
We can use Floyd's Tortoise and Hare (Cycle Detection) algorithm to find the duplicate:

### Time Complexity:
- O(n)

### Space Complexity:
- O(1)

## Sample Code (C++)
```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];

        // Phase 1: Detect cycle
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);

        // Phase 2: Find entry point of the cycle
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};
```

## Tags
- Arrays
- Floyd Cycle Detection
- Tortoise and Hare Algorithm
- Duplicates
- Easy

