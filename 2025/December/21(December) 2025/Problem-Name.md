# Count X in Range of a Sorted Array

## Problem Statement

You are given a **sorted array** `arr[]` and a 2D array `queries[][]`, where each query is of the form:

```
[l, r, x]
```

For each query, count how many times the number `x` appears in the subarray `arr[l...r]` (inclusive).

---

## Examples

### Example 1

**Input:**

```
arr = [1, 2, 2, 4, 5, 5, 5, 8]
queries = [[0, 7, 5], [1, 2, 2], [0, 3, 7]]
```

**Output:**

```
[3, 2, 0]
```

**Explanation:**

* Query `[0, 7, 5]` → `5` appears **3** times
* Query `[1, 2, 2]` → `2` appears **2** times
* Query `[0, 3, 7]` → `7` appears **0** times

---

### Example 2

**Input:**

```
arr = [1, 3, 3, 3, 6, 7, 8]
queries = [[0, 3, 3], [4, 6, 3], [1, 5, 6]]
```

**Output:**

```
[3, 0, 1]
```

---

## Approach

Since the array is **sorted**, we can use **Binary Search** to efficiently answer each query.

For a given query `[l, r, x]`:

1. Use `lower_bound` to find the **first index** where `x` can appear.
2. Use `upper_bound` to find the **first index** greater than `x`.
3. Limit these indices to the range `[l, r]`.

### Formula

```
count = max(0, min(upper_bound(x), r+1) - max(lower_bound(x), l))
```

---

## Algorithm

For each query:

1. Compute `left = lower_bound(arr.begin(), arr.end(), x)`
2. Compute `right = upper_bound(arr.begin(), arr.end(), x)`
3. Adjust bounds using `l` and `r`
4. Add the count to the result

---

## C++ Implementation

```cpp
class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        int n = arr.size();

        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

            int start = max(left, l);
            int end = min(right, r + 1);

            if (start < end)
                result.push_back(end - start);
            else
                result.push_back(0);
        }

        return result;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(Q log N)`
* **Space Complexity:** `O(1)` (excluding output array)

---

## Key Takeaway

Using **binary search on a sorted array** allows each query to be answered efficiently, making this approach suitable for large inputs.
