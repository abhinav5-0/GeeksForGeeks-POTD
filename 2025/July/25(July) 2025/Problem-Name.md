# Max Circular Subarray Sum

**Difficulty:** Hard
**Accuracy:** 29.37%
**Submissions:** 168K+
**Points:** 8
**Average Time:** 25m

---

## Problem Statement

You are given a circular array `arr[]` of integers. Your task is to find the **maximum possible sum** of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning.

Return the maximum non-empty subarray sum, considering both **non-wrapping** and **wrapping** cases.

---

## Examples

### Example 1:

**Input:** `arr[] = [8, -8, 9, -9, 10, -11, 12]`
**Output:** `22`
**Explanation:** Starting from the last element `12`, the subarray `[12, 8, -8, 9, -9, 10]` gives a sum of `22`.

### Example 2:

**Input:** `arr[] = [10, -3, -4, 7, 6, 5, -4, -1]`
**Output:** `23`
**Explanation:** The subarray `[7, 6, 5, -4, -1, 10]` gives the maximum circular sum.

### Example 3:

**Input:** `arr[] = [5, -2, 3, 4]`
**Output:** `12`
**Explanation:** The subarray `[3, 4, 5]` (circular) gives the sum `12`.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `-10^4 ≤ arr[i] ≤ 10^4`

---

## Approach

To solve this problem, we consider two cases:

### Case 1: Non-Circular Subarray

Use **Kadane's Algorithm** to find the maximum subarray sum without wrapping.

### Case 2: Circular Subarray

Key formula:

```
Max Circular Sum = Total Sum of Array - Minimum Subarray Sum
```

* Compute the minimum subarray sum using a modified Kadane's.
* Subtract it from the total array sum.

### Special Case

If all elements are negative, then the circular subarray sum logic gives `0`, which is invalid. In that case, return the maximum element (non-circular max).

---

## Code

```cpp
class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int totalSum = 0;
        int maxKadane = INT_MIN, currMax = 0;
        int minKadane = INT_MAX, currMin = 0;

        for (int num : arr) {
            // For max subarray (Kadane's)
            currMax = max(num, currMax + num);
            maxKadane = max(maxKadane, currMax);

            // For min subarray
            currMin = min(num, currMin + num);
            minKadane = min(minKadane, currMin);

            // Total sum
            totalSum += num;
        }

        // If all numbers are negative, maxKadane is the result
        if (maxKadane < 0) return maxKadane;

        // Otherwise, max of normal and circular
        return max(maxKadane, totalSum - minKadane);
    }
};
```

---

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

---

## Tags

`Kadane's Algorithm`, `Dynamic Programming`, `Array`, `Circular Array`, `Prefix Sum`

