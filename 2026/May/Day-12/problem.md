# Range LCM Queries

**Difficulty:** Medium
**Accuracy:** 52.98%
**Submissions:** 15K+
**Points:** 4
**Average Time:** 45m

---

Given an array `arr[]` and a list of queries `queries[][]`. Each query can be one of the following two types:

* **Update Query:** `[1, index, value]`
  Update the element at position `index` in the array to the given value.

* **Range Query:** `[2, L, R]`
  Compute and return the **Least Common Multiple (LCM)** of all elements in the subarray from index `L` to `R` (inclusive).

Process all queries sequentially and return a list containing the results of all Type 2 queries.

> **Note:** All operations follow 0-based indexing.

---

## Examples

### Example 1

**Input:**

```text
arr[] = [2, 3, 4, 6, 8, 16]
queries[][] = [[2, 0, 2], [1, 3, 8], [2, 2, 5]]
```

**Output:**

```text
[12, 16]
```

**Explanation:**

```text
[2, 0, 2]: LCM of [2, 3, 4] = 12
[1, 3, 8]: array becomes [2, 3, 4, 8, 8, 16]
[2, 2, 5]: LCM of [4, 8, 8, 16] = 16
```

---

### Example 2

**Input:**

```text
arr[] = [1, 2, 3, 4]
queries[][] = [[2, 0, 3], [1, 0, 5], [2, 0, 1]]
```

**Output:**

```text
[12, 10]
```

**Explanation:**

```text
[2, 0, 3]: LCM of [1, 2, 3, 4] = 12
[1, 0, 5]: array becomes [5, 2, 3, 4]
[2, 0, 1]: LCM of [5, 2] = 10
```

---

## Constraints

```text
1 ≤ arr.size() ≤ 10^4
1 ≤ queries.size() ≤ 10^5
0 ≤ L ≤ R ≤ arr.size() - 1
0 ≤ index ≤ arr.size() - 1
1 ≤ arr[i], value ≤ 10^4
```

---

## Function Signature

```cpp
class Solution {
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
    }
};
```

---

## Approach Hint

* Use **GCD** to compute LCM efficiently:

```cpp
lcm(a, b) = (a / gcd(a, b)) * b
```

* Since there are update and range queries, a **Segment Tree** can optimize operations:

  * Build segment tree with LCM values.
  * Update operation in `O(log n)`.
  * Range LCM query in `O(log n)`.

---

## Sample Efficient LCM Function

```cpp
long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}
```
