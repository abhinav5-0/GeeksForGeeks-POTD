# Elements in Range [a, b]

## Problem Statement

You are given:

* An **unsorted array** `arr[]`
* A 2D array `queries[][]` of size `q`, where each query is of the form `[a, b]`

For each query, count how many elements in `arr[]` lie within the range **[a, b]**, i.e., elements satisfying:

```
a ≤ x ≤ b
```

Return the result for all queries as a list of integers.

---

## Examples

### Example 1

**Input:**

```
arr = [1, 4, 2, 8, 5]
queries = [[1, 4], [3, 6], [0, 10]]
```

**Output:**

```
[3, 2, 5]
```

**Explanation:**

* Query [1, 4] → Elements: [1, 4, 2] → Count = 3
* Query [3, 6] → Elements: [4, 5] → Count = 2
* Query [0, 10] → All elements → Count = 5

---

### Example 2

**Input:**

```
arr = [10, 20, 30, 40, 50]
queries = [[5, 15], [25, 45], [10, 50]]
```

**Output:**

```
[1, 2, 5]
```

---

## Constraints

* `1 ≤ arr.size(), q ≤ 10^5`
* `0 ≤ arr[i] ≤ 10^6`

---

## Approach (Efficient Solution)

1. **Sort the array** `arr[]`.
2. For each query `[a, b]`:

   * Use `lower_bound` to find the first index where value ≥ `a`.
   * Use `upper_bound` to find the first index where value > `b`.
3. The difference between these indices gives the count of elements in range.

---

## Algorithm

```
1. Sort arr
2. For each query [a, b]:
   a. left = lower_bound(arr, a)
   b. right = upper_bound(arr, b)
   c. answer = right - left
3. Return all answers
```

---

## C++ Implementation

```cpp
class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        vector<int> result;
        
        // Step 2: Process each query
        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];
            
            int left = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
            
            result.push_back(right - left);
        }
        
        return result;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:**

  * Sorting: `O(n log n)`
  * Queries: `O(q log n)`
* **Space Complexity:** `O(1)` (excluding output)

---

## Key Takeaways

* Sorting + Binary Search is ideal for range queries
* `lower_bound` and `upper_bound` are powerful STL tools
* Efficient even for large inputs

---

✨ *Interview-friendly and scalable solution*
