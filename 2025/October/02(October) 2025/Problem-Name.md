# Unique K-Number Sum

**Difficulty:** Medium  
**Accuracy:** 73.03%  
**Submissions:** 8K+  
**Points:** 4

---

## Problem Statement
Given two integers `n` and `k`, the task is to find all valid combinations of `k` numbers that add up to `n` based on the following conditions:

- Only numbers from the range [1, 9] can be used.
- Each number can only be used at most once.

**Note:** You can return the combinations in any order, the driver code will print them in sorted order.

---

## Examples

### Example 1
**Input:**  
`n = 9, k = 3`  
**Output:**  
`[[1, 2, 6], [1, 3, 5], [2, 3, 4]]`  
**Explanation:** There are three valid combinations of 3 numbers that sum to 9: `[1, 2, 6]`, `[1, 3, 5]` and `[2, 3, 4]`.

### Example 2
**Input:**  
`n = 3, k = 3`  
**Output:**  
`[]`  
**Explanation:** It is not possible to pick 3 distinct numbers from 1 to 9 that sum to 3, so no valid combinations exist.

---

## Constraints
- 1 ≤ n ≤ 50  
- 1 ≤ k ≤ 9

---

## Approach
This is a **backtracking / combinatorial search problem**.

1. Use DFS/backtracking to explore possible number choices.
2. Keep track of:
   - Current combination (`temp`)
   - Remaining sum (`n`)
   - Start index to avoid duplicates
3. Base cases:
   - If `temp.size() == k` and `n == 0` → add combination to result.
   - If `n < 0` → stop.
4. Try numbers from `start` to `9`.

The problem reduces to generating **combinations** of numbers from `1–9` that sum to `n` with exactly `k` numbers.

---

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int n, int k, int start, vector<int>& temp) {
        if (temp.size() == k) {
            if (n == 0) ans.push_back(temp);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) break; // prune
            temp.push_back(i);
            backtrack(n - i, k, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(int n, int k) {
        vector<int> temp;
        backtrack(n, k, 1, temp);
        return ans;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** O(2^9) = O(512), since we only check subsets of numbers 1–9.
- **Space Complexity:** O(k), recursion depth and temporary storage.

---

✅ Efficient and works within given constraints.
