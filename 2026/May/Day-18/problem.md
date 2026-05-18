````md
# Maximum Sum Problem

## Problem Statement

Given a number **n**, find its maximum sum value using the following recursive breaks:

- Break the number into three parts:
  - `n/2`
  - `n/3`
  - `n/4`
- Only the integer part (floor value) is considered.
- Each obtained number can be further divided recursively.
- At every step, choose the maximum between:
  - the current number itself
  - the sum obtained after recursive division

It is also allowed to keep the number as it is without dividing.

---

## Examples

### Example 1

**Input:**
```txt
n = 12
````

**Output:**

```txt
13
```

**Explanation:**

Break `12` into:

```txt
12/2 = 6
12/3 = 4
12/4 = 3
```

Sum becomes:

```txt
6 + 4 + 3 = 13
```

Further breaking `6`, `4`, and `3` does not produce a greater value.

---

### Example 2

**Input:**

```txt
n = 24
```

**Output:**

```txt
27
```

**Explanation:**

Break `24` into:

```txt
24/2 = 12
24/3 = 8
24/4 = 6
```

Current sum:

```txt
12 + 8 + 6 = 26
```

Now recursively break `12`:

```txt
12 → 13
```

So final answer becomes:

```txt
13 + 8 + 6 = 27
```

---

## Constraints

```txt
0 ≤ n ≤ 10^6
```

---

# Approach (Dynamic Programming)

We use **Bottom-Up DP**.

Let:

```txt
dp[i] = maximum sum obtainable from i
```

For every number `i`:

```txt
dp[i] = max(i, dp[i/2] + dp[i/3] + dp[i/4])
```

### Steps

1. Initialize DP array.
2. Iterate from `0` to `n`.
3. Either:

   * keep the number itself
   * or split recursively
4. Store the maximum value.

---

# C++ Solution

```cpp
class Solution {
public:
    int maxSum(int n) {

        vector<int> dp(n + 1, 0);

        for(int i = 0; i <= n; i++) {

            dp[i] = max(i,
                        dp[i / 2] +
                        dp[i / 3] +
                        dp[i / 4]);
        }

        return dp[n];
    }
};
```

---

# Time Complexity

```txt
O(n)
```

Because each number from `0` to `n` is processed once.

---

# Space Complexity

```txt
O(n)
```

For storing the DP array.

```
```
