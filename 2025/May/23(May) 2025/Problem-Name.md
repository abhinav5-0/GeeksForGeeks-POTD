# Dice Throw Problem

## Difficulty

Medium

## Accuracy

36.52%

## Submissions

37K+

## Points

4

## Average Time

30 minutes

---

## Problem Statement

Given `n` dice each with `m` faces, find the number of ways to get sum `x`, which is the summation of values on each face when all the dice are thrown.

---

## Input Format

* An integer `m` representing the number of faces on each die.
* An integer `n` representing the number of dice.
* An integer `x` representing the desired sum.

---

## Output Format

* An integer representing the number of ways to achieve the sum `x` using `n` dice with `m` faces.

---

## Examples

### Example 1:

**Input:**

```
m = 6
n = 3
x = 12
```

**Output:**

```
25
```

**Explanation:**
There are 25 total ways to get the sum 12 using 3 dice with faces from 1 to 6.

### Example 2:

**Input:**

```
m = 2
n = 3
x = 6
```

**Output:**

```
1
```

**Explanation:**
There is only 1 way to get the sum 6 using 3 dice with faces from 1 to 2. All the dice will have to land on 2.

---

## Constraints

* 1 <= m, n, x <= 50

---

## Approach

Use Dynamic Programming (DP) to solve this problem.

### Define:

Let `dp[i][j]` be the number of ways to get a sum `j` using `i` dice.

### Transition:

```
dp[i][j] = sum(dp[i-1][j-k]) for all k in [1, m] and j-k >= 0
```

### Base Case:

```
dp[0][0] = 1  // One way to get sum 0 with 0 dice
```

---

## C++ Code

```cpp
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;

        for (int dice = 1; dice <= n; ++dice) {
            for (int sum = 1; sum <= x; ++sum) {
                for (int face = 1; face <= m; ++face) {
                    if (sum - face >= 0)
                        dp[dice][sum] += dp[dice - 1][sum - face];
                }
            }
        }

        return dp[n][x];
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(n \* x \* m)
* **Space Complexity:** O(n \* x)
