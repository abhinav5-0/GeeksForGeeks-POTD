# Minimize the Heights II

### Problem Statement
You are given an array `arr[]` denoting heights of `n` towers and a positive integer `k`.

For each tower, you must perform **exactly one** of the following operations:
- Increase the height of the tower by `k`
- Decrease the height of the tower by `k` (only if the result is non-negative)

You need to find out the **minimum possible difference** between the height of the shortest and tallest towers after modification.

---

### Examples

**Input:**  
`k = 2, arr[] = [1, 5, 8, 10]`  
**Output:**  
`5`  
**Explanation:**  
Modified array: `[3, 3, 6, 8]` → Difference = `8 - 3 = 5`

**Input:**  
`k = 3, arr[] = [3, 9, 12, 16, 20]`  
**Output:**  
`11`  
**Explanation:**  
Modified array: `[6, 12, 9, 13, 17]` → Difference = `17 - 6 = 11`

---

### Constraints
- `1 ≤ k ≤ 10^7`
- `1 ≤ n ≤ 10^5`
- `1 ≤ arr[i] ≤ 10^7`

---

### Approach
1. **Sort** the array.
2. Initial difference = `arr[n-1] - arr[0]`.
3. Possible new minimum = either `arr[0] + k` or some `arr[i+1] - k`.
4. Possible new maximum = either `arr[n-1] - k` or some `arr[i] + k`.
5. Iterate through the array to check all partitions and update the answer.

---

### C++ Implementation
```cpp
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        sort(arr.begin(), arr.end());
        int ans = arr[n-1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;

        for (int i = 0; i < n - 1; i++) {
            int min_height = min(smallest, arr[i+1] - k);
            int max_height = max(largest, arr[i] + k);

            if (min_height < 0) continue;

            ans = min(ans, max_height - min_height);
        }

        return ans;
    }
};
```

---

### Complexity Analysis
- **Time Complexity:** `O(n log n)` (due to sorting)
- **Space Complexity:** `O(1)` (in-place calculations)

---

### Dry Run Example
Input:  
`k = 2, arr = [1, 5, 8, 10]`

Sorted array: `[1, 5, 8, 10]`
- Initial diff = 9
- Partition checks:
  - i=0 → min=3, max=8 → diff=5
  - i=1 → min=3, max=8 → diff=5
  - i=2 → min=3, max=10 → diff=7

**Answer = 5** ✅
