# Max Profit from Two Machines

## Problem Statement

Given two machines, Machine A and Machine B, and a set of `n` tasks.

* If Machine A performs the `i-th` task, profit = `a[i]`
* If Machine B performs the `i-th` task, profit = `b[i]`

Machine A can process at most `x` tasks and Machine B can process at most `y` tasks.

It is guaranteed that:

```text
x + y >= n
```

Return the maximum possible profit after assigning every task to either Machine A or Machine B.

---

# Examples

## Example 1

### Input

```cpp
x = 3, y = 3

a[] = [1, 2, 3, 4, 5]
b[] = [5, 4, 3, 2, 1]
```

### Output

```cpp
21
```

### Explanation

Machine A performs tasks with indices `[2, 3, 4]`

Profit from A:

```text
3 + 4 + 5 = 12
```

Machine B performs tasks with indices `[0, 1]`

Profit from B:

```text
5 + 4 = 9
```

Total Profit:

```text
12 + 9 = 21
```

---

## Example 2

### Input

```cpp
x = 4, y = 4

a[] = [1, 4, 3, 2, 7, 5, 9, 6]
b[] = [1, 2, 3, 6, 5, 4, 9, 8]
```

### Output

```cpp
43
```

---

## Example 3

### Input

```cpp
x = 3, y = 4

a[] = [8, 7, 15, 19, 16, 18]
b[] = [1, 7, 15, 11, 12, 31]
```

### Output

```cpp
110
```

---

# Constraints

```text
1 <= a.size() == b.size() <= 10^5
1 <= x, y <= 10^5
1 <= a[i], b[i] <= 10^4
```

---

# Approach

## Greedy Strategy

For every task:

* If `a[i] > b[i]`, Machine A gives more profit.
* If `b[i] > a[i]`, Machine B gives more profit.

We calculate the difference:

```cpp
abs(a[i] - b[i])
```

Tasks having larger difference are more important because choosing the wrong machine there causes greater loss.

So:

1. Store all task indices.
2. Sort them in descending order of:

```cpp
abs(a[i] - b[i])
```

3. Assign tasks greedily:

   * If A gives more profit and A still has capacity → assign to A
   * Else assign to B
   * Similarly for B

This ensures maximum total profit.

---

# Time Complexity

## Sorting

```text
O(n log n)
```

## Traversal

```text
O(n)
```

## Overall

```text
O(n log n)
```

---

# Space Complexity

```text
O(n)
```

---

# C++ Solution

```cpp
class Solution {
public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        
        vector<int> idx(n);
        
        for(int i = 0; i < n; i++) {
            idx[i] = i;
        }

        // Sort by absolute difference
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return abs(a[i] - b[i]) > abs(a[j] - b[j]);
        });

        int profit = 0;

        for(int i : idx) {
            // Prefer Machine A
            if((a[i] >= b[i] && x > 0) || y == 0) {
                profit += a[i];
                x--;
            }
            else {
                profit += b[i];
                y--;
            }
        }

        return profit;
    }
};
```

---

# Dry Run

## Input

```cpp
x = 3
y = 3

a = [1, 2, 3, 4, 5]
b = [5, 4, 3, 2, 1]
```

## Differences

| Index | a[i] | b[i] | Difference |
| ----- | ---- | ---- | ---------- |
| 0     | 1    | 5    | 4          |
| 1     | 2    | 4    | 2          |
| 2     | 3    | 3    | 0          |
| 3     | 4    | 2    | 2          |
| 4     | 5    | 1    | 4          |

Sorted order by difference:

```text
[0, 4, 1, 3, 2]
```

Assignments:

| Task | Chosen Machine | Profit |
| ---- | -------------- | ------ |
| 0    | B              | 5      |
| 4    | A              | 5      |
| 1    | B              | 4      |
| 3    | A              | 4      |
| 2    | A              | 3      |

Total:

```text
5 + 5 + 4 + 4 + 3 = 21
```

---

# Key Interview Point

The main idea is:

> Prioritize tasks where the profit difference between A and B is maximum.

Because making the wrong assignment there causes maximum loss.
