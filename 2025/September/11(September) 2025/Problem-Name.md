# Minimum Jumps Problem

## Problem Statement
You are given an array `arr[]` of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.

- If `arr[i] = 3`, you can jump to index `i + 1`, `i + 2`, or `i + 3` from position `i`.
- If `arr[i] = 0`, you cannot jump forward from that position.

Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Return `-1` if you cannot reach the end of the array.

### Constraints:
- `2 ≤ arr.size() ≤ 10^5`
- `0 ≤ arr[i] ≤ 10^5`

---

## Examples

**Input:**
```cpp
arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
```
**Output:**
```
3
```
**Explanation:**
- First jump: from 1st element (value 1) to 2nd element (value 3).
- Second jump: from 2nd element to 5th element (value 9).
- Third jump: directly to the last element.

---

**Input:**
```cpp
arr = [1, 4, 3, 2, 6, 7]
```
**Output:**
```
2
```
**Explanation:**
- First jump: from 1st element to 2nd element (value 4).
- Second jump: directly to the last element.

---

**Input:**
```cpp
arr = [0, 10, 20]
```
**Output:**
```
-1
```
**Explanation:**
We cannot move anywhere from the 1st element.

---

## Approach
We can solve this problem using a **Greedy Algorithm** by tracking the maximum reachable index and the steps left in the current jump.

### Key Idea
- Maintain three variables:
  - `maxReach`: The farthest index reachable so far.
  - `steps`: Remaining steps in the current jump.
  - `jumps`: Number of jumps made so far.
- Iterate through the array:
  - Update `maxReach` with `max(maxReach, i + arr[i])`.
  - Decrement `steps`.
  - If `steps` becomes 0, increment `jumps` and reset `steps = maxReach - i`.
  - If at any point `i >= maxReach`, return `-1` (stuck).

### Time and Space Complexity
- **Time Complexity:** `O(n)` (single pass).
- **Space Complexity:** `O(1)` (constant extra memory).

---

## C++ Implementation
```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;
        
        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;
        
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
```

---

## Dry Run Example

### Input: `arr = [1, 4, 3, 2, 6, 7]`

- Start: `jumps=1`, `maxReach=1`, `steps=1`
- i=1 → `maxReach=5`, `steps=0` → need jump → `jumps=2`, `steps=4`
- i=2 → `maxReach=5`, `steps=3`
- i=3 → `maxReach=5`, `steps=2`
- i=4 → `maxReach=10`, `steps=1`
- i=5 → reached last index → answer = `2`

✅ Output = 2
