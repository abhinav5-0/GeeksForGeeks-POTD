# Search for Subarray

## Problem Statement

You are given two integer arrays `a[]` and `b[]`.
Return all the **starting indexes** of all occurrences of `b[]` as a **subarray** in `a[]`.

---

## Examples

### Example 1

#### Input

```text
a[] = [2, 4, 1, 0, 4, 1, 1]
b[] = [4, 1]
```

#### Output

```text
[1, 4]
```

#### Explanation

`b[]` occurs as a subarray in `a[]`:

* From index `1` to `2`
* From index `4` to `5`

---

### Example 2

#### Input

```text
a[] = [2, 4, 1, 0, 0, 3]
b[] = [0]
```

#### Output

```text
[3, 4]
```

#### Explanation

`b[]` occurs as a subarray in `a[]`:

* From index `3` to `3`
* From index `4` to `4`

---

### Example 3

#### Input

```text
a[] = [1, 3, 5, 3, 0]
b[] = [1, 3, 0]
```

#### Output

```text
[]
```

#### Explanation

No subarray equal to `b[]` exists in `a[]`.

---

## Constraints

```text
1 ≤ a.size() ≤ 10^6
1 ≤ b.size() ≤ a.size()
0 ≤ a[i], b[i] ≤ 10^4
```

---

# Approach

We check every possible starting index in array `a[]`.

For each index `i`:

1. Compare elements of `b[]` with the corresponding elements in `a[]`
2. If all elements match, store index `i`
3. Continue checking remaining positions

---

# Optimized Idea

Instead of creating extra arrays, directly compare elements.

* Time Complexity: **O((n - m + 1) × m)**
* Space Complexity: **O(1)** (excluding answer array)

Where:

* `n = size of a[]`
* `m = size of b[]`

---

# C++ Solution

```cpp
class Solution {
public:
    vector<int> search(vector<int>& a, vector<int>& b) {
        vector<int> ans;

        int n = a.size();
        int m = b.size();

        for (int i = 0; i <= n - m; i++) {
            bool found = true;

            for (int j = 0; j < m; j++) {
                if (a[i + j] != b[j]) {
                    found = false;
                    break;
                }
            }

            if (found)
                ans.push_back(i);
        }

        return ans;
    }
};
```

---

# Dry Run

## Input

```text
a[] = [2, 4, 1, 0, 4, 1, 1]
b[] = [4, 1]
```

## Step-by-Step

### i = 0

```text
[2, 4] != [4, 1]
```

Not matched.

### i = 1

```text
[4, 1] == [4, 1]
```

Matched → store `1`

### i = 2

```text
[1, 0] != [4, 1]
```

Not matched.

### i = 3

```text
[0, 4] != [4, 1]
```

Not matched.

### i = 4

```text
[4, 1] == [4, 1]
```

Matched → store `4`

## Final Answer

```text
[1, 4]
```

---

# Key Points

* We compare `b[]` with every possible subarray of size `m`
* If all elements match, the starting index is added
* Simple and efficient for interview and coding practice problems
