# Maximize Median After K Additions

## Problem Statement

Given an array `arr[]` consisting of positive integers and an integer `k`. You are allowed to perform at most `k` operations, where in each operation, you can increment any one element of the array by 1. Determine the maximum possible median of the array that can be achieved after performing at most `k` such operations.

**Note:**

* The median of an array is defined as the middle element when the array (after sorting) has an odd size, or the average of the two middle elements when the array (after sorting) has an even size.

---

## Examples

### Example 1

**Input:**

```
arr = [1, 3, 4, 5], k = 3
```

**Output:**

```
5
```

**Explanation:**
We can add +2 to the second element and +1 to the third element to get the array `[1, 5, 5, 5]`. After sorting, the array remains `[1, 5, 5, 5]`. Since the length is even, the median is `(5 + 5) / 2 = 5`.

---

### Example 2

**Input:**

```
arr = [1, 3, 6, 4, 2], k = 10
```

**Output:**

```
7
```

**Explanation:**
After applying operations optimally, we can transform the array to `[1, 2, 7, 7, 7]`. Sorted array becomes `[1, 2, 7, 7, 7]`. Since the length is odd, the median is the middle element `7`.

---

## Constraints

* 1 ≤ arr.size() ≤ 10^5
* 0 ≤ arr\[i], k ≤ 10^9

---

## Approach

1. **Sort the array** to fix the median positions.
2. **Identify the median index**:

   * Odd `n`: median at `n/2`.
   * Even `n`: median = `(arr[n/2 - 1] + arr[n/2]) / 2` (focus on increasing `arr[n/2]`).
3. **Distribute increments greedily** to raise the median:

   * Level up the median and higher elements step by step using available `k`.
   * Stop when `k` runs out.
4. **Return the final median** based on odd/even size.

---

## Solution Code (C++)

```cpp
class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int index = n / 2;  // focus on upper middle for even case

        long long kk = k;
        for (int i = index; i < n - 1; i++) {
            long long need = 1LL * (i + 1 - index) * (arr[i + 1] - arr[index]);
            if (need <= kk) {
                kk -= need;
                arr[index] = arr[i + 1];
            } else {
                arr[index] += kk / (i + 1 - index);
                kk = 0;
                break;
            }
        }
        if (kk > 0) {
            arr[index] += kk / (n - index);
        }

        // Final median calculation
        if (n % 2 == 1) {
            return arr[index];
        } else {
            return (arr[n/2 - 1] + arr[n/2]) / 2;
        }
    }
};
```

---

## Complexity Analysis

* Sorting: **O(n log n)**
* Greedy leveling: **O(n)**
* Total: **O(n log n)**, efficient for `n ≤ 10^5`.

---

## Key Idea

* Focus on increasing the **middle element (or upper middle for even n)**, since raising these maximizes the median.
* Use greedy "level up" strategy to distribute increments optimally.
