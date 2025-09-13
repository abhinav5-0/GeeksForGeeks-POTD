# Minimum Cost to Cut a Board into Squares

## Problem Statement
Given a board of dimensions `n × m` that needs to be cut into `n*m` squares. The cost of making a cut along a horizontal or vertical edge is provided in two arrays:

- `x[]`: Cutting costs along the vertical edges (length-wise).
- `y[]`: Cutting costs along the horizontal edges (width-wise).

Find the minimum total cost required to cut the board into squares optimally.

---

## Examples

### Example 1
**Input:**
```
n = 4, m = 6
x[] = [2, 1, 3, 1, 4]
y[] = [4, 1, 2]
```

**Output:**
```
42
```

**Explanation:**
Optimal sequence of cuts results in a minimum total cost of 42.

---

### Example 2
**Input:**
```
n = 4, m = 4
x[] = [1, 1, 1]
y[] = [1, 1, 1]
```

**Output:**
```
15
```

**Explanation:**
Optimal sequence of cuts results in a minimum total cost of 15.

---

## Constraints
- `2 ≤ n, m ≤ 10^3`
- `1 ≤ x[i], y[j] ≤ 10^3`

---

## Approach
This is a **greedy algorithm problem**:
- Always pick the **largest cut cost first**, because earlier cuts affect fewer segments, minimizing total cost.

### Steps:
1. Sort both `x` and `y` arrays in **descending order**.
2. Maintain counters:
   - `horizontal_segments = 1`
   - `vertical_segments = 1`
3. Use two pointers (`i` for `x`, `j` for `y`). At each step:
   - If `x[i] >= y[j]`: perform a **vertical cut** → cost = `x[i] * horizontal_segments`.
   - Else: perform a **horizontal cut** → cost = `y[j] * vertical_segments`.
4. Update respective segment counters.
5. Continue until all cuts are done.

---

## C++ Implementation
```cpp
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort in descending order
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int i = 0, j = 0;
        int horizontal_segments = 1, vertical_segments = 1;
        long long total_cost = 0;

        // Greedy cutting
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                total_cost += (long long)x[i] * horizontal_segments;
                vertical_segments++;
                i++;
            } else {
                total_cost += (long long)y[j] * vertical_segments;
                horizontal_segments++;
                j++;
            }
        }

        // Remaining vertical cuts
        while (i < x.size()) {
            total_cost += (long long)x[i] * horizontal_segments;
            vertical_segments++;
            i++;
        }

        // Remaining horizontal cuts
        while (j < y.size()) {
            total_cost += (long long)y[j] * vertical_segments;
            horizontal_segments++;
            j++;
        }

        return (int)total_cost;
    }
};
```

---

## Complexity Analysis
- **Time Complexity:** `O(n log n + m log m)` (due to sorting).
- **Space Complexity:** `O(1)` (ignoring input storage).
