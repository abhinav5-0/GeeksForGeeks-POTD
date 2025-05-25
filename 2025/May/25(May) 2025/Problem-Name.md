# Pythagorean Triplet Problem

**Difficulty:** Medium
**Accuracy:** 24.77%
**Submissions:** 228K+
**Points:** 4
**Average Time:** 20m

---

## Problem Statement

Given an array `arr[]`, return `true` if there is a triplet `(a, b, c)` from the array (where `a`, `b`, and `c` are at different indices) that satisfies:

$a^2 + b^2 = c^2$

Otherwise, return `false`.

---

## Examples

### Example 1

**Input:**

```cpp
arr[] = [3, 2, 4, 6, 5]
```

**Output:**

```
true
```

**Explanation:**
Triplet (3, 4, 5) satisfies 3^2 + 4^2 = 5^2

### Example 2

**Input:**

```cpp
arr[] = [3, 8, 5]
```

**Output:**

```
false
```

**Explanation:**
No Pythagorean triplet found.

### Example 3

**Input:**

```cpp
arr[] = [1, 1, 1]
```

**Output:**

```
false
```

---

## Constraints

* 1 <= `arr.size()` <= 10^5
* 1 <= `arr[i]` <= 10^3

---

## C++ Implementation

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        vector<long long> squared(n);

        // Step 1: Square all elements
        for (int i = 0; i < n; ++i) {
            squared[i] = 1LL * arr[i] * arr[i];
        }

        // Step 2: Sort the squared array
        sort(squared.begin(), squared.end());

        // Step 3: Fix one element as c^2 and find a^2 + b^2 = c^2
        for (int i = n - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                long long sum = squared[left] + squared[right];
                if (sum == squared[i]) return true;
                else if (sum < squared[i]) ++left;
                else --right;
            }
        }

        return false;
    }
};
```

---

## Time and Space Complexity

* **Time Complexity:** O(n^2) in worst case (due to two-pointer search for each fixed `c`)
* **Space Complexity:** O(n) for storing squares

---

## Tags

`Arrays`, `Two Pointers`, `Mathematics`, `Sorting`

---

## Notes

This is a classic example of using two-pointer technique combined with sorting to reduce the time complexity from brute-force O(n^3) to O(n^2).

Use squaring carefully to avoid integer overflows (use `long long`).
