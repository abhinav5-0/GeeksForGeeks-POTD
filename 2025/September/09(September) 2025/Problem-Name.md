# Assign Mice Holes

**Difficulty:** Easy  
**Accuracy:** 55.93%  
**Points:** 2

---

## Problem Statement
You are given two arrays `mices[]` and `holes[]` of the same size. The array `mices[]` represents the positions of the mice on a straight line, while the array `holes[]` represents the positions of the holes on the same line. Each hole can accommodate exactly one mouse. A mouse can either stay in its current position, move one step to the right, or move one step to the left, and each move takes one minute. The task is to assign each mouse to a distinct hole in such a way that the time taken by the last mouse to reach its hole is minimized.

---

## Examples

**Example 1:**
```
Input: mices[] = [4, -4, 2], holes[] = [4, 0, 5]
Output: 4
Explanation: 
Assign the mouse at 4 → hole at 4 → time = 0
Assign the mouse at -4 → hole at 0 → time = 4
Assign the mouse at 2 → hole at 5 → time = 3
Maximum time = 4
```

**Example 2:**
```
Input: mices[] = [1, 2], holes[] = [20, 10]
Output: 18
Explanation:
Assign the mouse at 1 → hole at 10 → time = 9
Assign the mouse at 2 → hole at 20 → time = 18
Maximum time = 18
```

---

## Constraints
- 1 ≤ mices.size() = holes.size() ≤ 10^5
- -10^5 ≤ mices[i], holes[i] ≤ 10^5

---

## Approach
This is a **greedy problem**.

1. Sort both `mices[]` and `holes[]`.
2. Pair the i-th mouse with the i-th hole.
3. Compute the time as the absolute difference: `|mices[i] - holes[i]|`.
4. The result is the maximum of all these values.

**Why Sorting Works?**
- If we don’t sort, some mice may travel unnecessarily long distances.
- Sorting ensures the optimal one-to-one assignment that minimizes the maximum travel time.

---

## Complexity
- **Time Complexity:** `O(n log n)` (due to sorting)
- **Space Complexity:** `O(1)` (in-place sorting)

---

## C++ Solution
```cpp
class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // Step 1: Sort both arrays
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int n = mices.size();
        int maxTime = 0;
        
        // Step 2: Pair ith mouse with ith hole
        for(int i = 0; i < n; i++) {
            maxTime = max(maxTime, abs(mices[i] - holes[i]));
        }
        
        return maxTime;
    }
};
