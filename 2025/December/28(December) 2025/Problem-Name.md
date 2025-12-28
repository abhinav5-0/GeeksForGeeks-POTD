# Minimum Time to Fulfil All Orders

## Problem Statement

Geek is organizing a party and needs exactly **n donuts**. There are **m chefs**, and each chef has a **rank r**.

A chef with rank `r` makes donuts as follows:

* 1st donut → `r` minutes
* 2nd donut → `2r` minutes
* 3rd donut → `3r` minutes
* ...and so on

A chef can only start the next donut after finishing the previous one. All chefs work **simultaneously**.

The task is to find the **minimum time** required to make at least `n` donuts.

---

## Key Insight

For a chef with rank `r`, the time required to make `k` donuts is:

```
Time = r × (1 + 2 + 3 + ... + k)
     = r × k(k + 1) / 2
```

Given a time `T`, we can calculate how many donuts each chef can make within that time.

---

## Approach (Binary Search on Time)

1. **Search Space**:

   * `low = 0`
   * `high = minRank × n × (n + 1) / 2`

2. **Binary Search** on time:

   * For a guessed time `mid`, compute total donuts all chefs can make
   * If total donuts ≥ `n`, try smaller time
   * Else, increase time

3. The smallest valid time is the answer

---

## Helper Function Logic

For each chef, we find the **maximum donuts** he can make within time `T` using binary search on `k` such that:

```
r × k(k + 1) / 2 ≤ T
```

---

## C++ Implementation

```cpp
class Solution {
  public:
    bool canMake(int time, vector<int>& ranks, int n) {
        int total = 0;

        for (int r : ranks) {
            int low = 0, high = n;
            int donuts = 0;

            while (low <= high) {
                int mid = (low + high) / 2;
                long long required = 1LL * r * mid * (mid + 1) / 2;

                if (required <= time) {
                    donuts = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            total += donuts;
            if (total >= n) return true;
        }
        return false;
    }

    int minTime(vector<int>& ranks, int n) {
        int minRank = *min_element(ranks.begin(), ranks.end());
        int low = 0;
        int high = minRank * n * (n + 1) / 2;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(mid, ranks, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```

---

## Example

### Input

```
n = 10
ranks = [1, 2, 3, 4]
```

### Output

```
12
```

---

## Complexity Analysis

* **Time Complexity**: `O(m × log n × log T)`
* **Space Complexity**: `O(1)`

---

## Tags

`Binary Search` `Math` `Greedy` `Scheduling`
