# K-th Largest Sum Contiguous Subarray

## Problem Statement

Given an array `arr[]` of size `n`, find the sum of the **K-th largest** sum among all **contiguous subarrays**. In other words, identify the K-th largest sum from all possible subarrays and return it.

## Examples

### Example 1:

**Input:**

```cpp
arr[] = [3, 2, 1], k = 2
```

**Output:**

```
5
```

**Explanation:**
All contiguous subarray sums: \[6, 5, 3, 2, 1]. The 2nd largest is 5.

### Example 2:

**Input:**

```cpp
arr[] = [2, 6, 4, 1], k = 3
```

**Output:**

```
11
```

**Explanation:**
All contiguous subarray sums: \[13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. The 3rd largest is 11.

## Constraints

* `1 <= arr.size() <= 1000`
* `1 <= k <= (n * (n + 1)) / 2`
* `-10^5 <= arr[i] <= 10^5`

## C++ Function Signature

```cpp
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k);
};
```

## Efficient Approach

Use a **min-heap (priority\_queue)** of size `k` to keep track of the top `k` largest subarray sums.

### C++ Implementation

```cpp
int kthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (pq.size() < k) {
                pq.push(sum);
            } else if (sum > pq.top()) {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top();
}
```

## Time and Space Complexity

* **Time Complexity:** `O(n^2 * log k)` — `O(n^2)` subarrays and each heap operation takes `log k`.
* **Space Complexity:** `O(k)` for the min-heap.
