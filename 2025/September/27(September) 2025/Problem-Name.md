# Minimum K Consecutive Bit Flips

**Difficulty:** Hard
**Accuracy:** 69.6%
**Submissions:** 6K+
**Points:** 8

---

## Problem Statement

You are given a binary array `arr[]` (containing only 0's and 1's) and an integer `k`. In one operation, you can select a contiguous subarray of length `k` and flip all its bits (i.e., change every 0 to 1 and every 1 to 0).

Your task is to find the minimum number of such operations required to make the entire array consist of only 1's. If it is not possible, return `-1`.

---

## Examples

### Example 1

**Input:**
`arr = [1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1], k = 2`
**Output:**
`4`

**Explanation:**

1. Flip subarray `[2, 3] → [1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1]`
2. Flip subarray `[4, 5] → [1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1]`
3. Flip subarray `[5, 6] → [1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1]`
4. Flip subarray `[6, 7] → [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]`

---

### Example 2

**Input:**
`arr = [0, 0, 1, 1, 1, 0, 0], k = 3`
**Output:**
`-1`

**Explanation:**
It is not possible to convert all elements to 1's by performing any number of operations.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `1 ≤ k ≤ arr.size()`

---

## Approach

1. Traverse the array left to right.
2. If the current bit (after considering flips so far) is `0`, **must flip** starting at this position.
3. Use an auxiliary array `isFlipped` to track where flips start.
4. Maintain `flipCount` to record the number of active flips at the current index.
5. If `i + k > n` and we still need to flip, return `-1`.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)` (can be optimized to `O(1)` using a queue)

---

## Code Implementation (C++)

```cpp
class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> isFlipped(n, 0);  // track flip starts
        int flipCount = 0, ops = 0;

        for (int i = 0; i < n; i++) {
            // remove expired flip effect
            if (i >= k) {
                flipCount ^= isFlipped[i - k];
            }

            // if current bit after flips is 0 → must flip
            if ((arr[i] ^ flipCount) == 0) {
                if (i + k > n) return -1; // cannot flip outside array
                ops++;
                flipCount ^= 1; // start new flip
                isFlipped[i] = 1;
            }
        }
        return ops;
    }
};
```

---

## Walkthrough

For input `arr = [1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1], k = 2`:

* i=2 → must flip → ops=1
* i=4 → must flip → ops=2
* i=5 → must flip → ops=3
* i=6 → must flip → ops=4

Final array becomes all 1’s ✅

**Answer:** `4`

---

## Notes

* This problem requires a **greedy + sliding window** approach.
* Can be optimized further using a **queue-based O(1) space approach**.
