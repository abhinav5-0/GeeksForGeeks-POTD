# Pascal's Triangle - Nth Row

### Problem Statement
Given a positive integer `n`, return the **nth row** of Pascal's Triangle.

Pascal's Triangle is a triangular array of the binomial coefficients. Each number is the sum of the two directly above it. The triangle starts with 1 at the top and is constructed as follows:

```
Row 1:        [1]
Row 2:       [1, 1]
Row 3:      [1, 2, 1]
Row 4:     [1, 3, 3, 1]
Row 5:    [1, 4, 6, 4, 1]
... and so on
```

### Input
- A single integer `n` (1 ≤ n ≤ 20), the index of the row (1-based).

### Output
- A list of integers representing the `n`th row of Pascal's Triangle.

### Examples
#### Example 1:
**Input:** `n = 4`

**Output:** `[1, 3, 3, 1]`

#### Example 2:
**Input:** `n = 5`

**Output:** `[1, 4, 6, 4, 1]`

#### Example 3:
**Input:** `n = 1`

**Output:** `[1]`

---

### C++ Function Signature
```cpp
vector<int> nthRowOfPascalTriangle(int n);
```

### Constraints
- `1 ≤ n ≤ 20`

### Approach
- Start with the first element `1`.
- Use the relation: `C(n, k) = C(n, k-1) * (n - k) / k` to iteratively calculate each element of the row.
- Return the final list.

### Time Complexity
- O(n) – Each element of the row is calculated in constant time.

### Space Complexity
- O(n) – Space used to store the row.

---

### C++ Implementation
```cpp
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        const int MOD = 1e9 + 7;
        vector<int> row;
        row.push_back(1);  // First element is always 1

        long long prev = 1;
        for (int k = 1; k < n; ++k) {
            long long curr = (prev * (n - k)) / k;
            curr %= MOD;
            row.push_back((int)curr);
            prev = curr;
        }
        return row;
    }
};
