# Celebrity Problem

## Problem Statement
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix `mat[][]` of size `n*n` is used to represent people at the party such that if an element of row `i` and column `j` is set to `1`, it means ith person knows jth person.

You need to return the index of the celebrity in the party, if the celebrity does not exist, return `-1`.

**Note:** Follow 0-based indexing.

---

## Examples

### Example 1
**Input:**
```cpp
mat = [[1, 1, 0],
       [0, 1, 0],
       [0, 1, 1]]
```
**Output:**
```
1
```
**Explanation:**
- 0th and 2nd person both know 1st person.
- 1st person does not know anyone.
Therefore, 1 is the celebrity.

---

### Example 2
**Input:**
```cpp
mat = [[1, 1], 
       [1, 1]]
```
**Output:**
```
-1
```
**Explanation:**
Since both people know each other, there is no celebrity.

---

### Example 3
**Input:**
```cpp
mat = [[1]]
```
**Output:**
```
0
```
**Explanation:**
A single person at the party is trivially a celebrity.

---

## Constraints
- 1 ≤ `mat.size()` ≤ 1000
- 0 ≤ `mat[i][j]` ≤ 1
- `mat[i][i] = 1`

---

## Approach
We use the **two-pointer elimination method** to efficiently find the celebrity.

1. Start with two candidates `a = 0` and `b = n-1`.
2. If `a` knows `b`, then `a` cannot be celebrity → move `a++`.
   Else, `b` cannot be celebrity → move `b--`.
3. After one pass, we have only one possible **candidate**.
4. Verify the candidate:
   - Candidate should not know anyone.
   - Everyone else should know the candidate.

---

## C++ Solution
```cpp
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int a = 0, b = n - 1;

        // Step 1: Find candidate
        while (a < b) {
            if (mat[a][b] == 1) {
                // a knows b → a cannot be celebrity
                a++;
            } else {
                // a does not know b → b cannot be celebrity
                b--;
            }
        }

        int candidate = a;

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // Celebrity should not know i
                if (mat[candidate][i] == 1) return -1;
                // Everyone should know celebrity
                if (mat[i][candidate] == 0) return -1;
            }
        }

        return candidate;
    }
};
```

---

## Complexity Analysis
- **Step 1:** O(n) to find candidate
- **Step 2:** O(n) to verify
- **Total:** O(n)
- **Space Complexity:** O(1)

Efficient compared to brute force O(n²) approach.
