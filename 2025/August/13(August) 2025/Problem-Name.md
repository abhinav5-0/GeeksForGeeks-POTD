# Tywin's War Strategy

## Problem Statement

You are given an array `arr[]` of size `n`, where `arr[i]` represents the number of soldiers in the i-th troop. You are also given an integer `k`. A troop is considered *lucky* if its number of soldiers is a multiple of `k`. Find the minimum total number of soldiers to add across all troops so that at least `ceil(n / 2)` troops become lucky.

**Constraints:**

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ k ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^5`

---

## Examples

### Example 1

**Input:**

```
arr = [5, 6, 3, 2, 1], k = 2
```

**Output:**

```
1
```

**Explanation:**
By adding 1 soldier for the troop with 1 soldier, we get `[5, 6, 3, 2, 2]`. Now 3 out of 5 troops (6, 2, and 2) are multiples of 2, satisfying the requirement.

### Example 2

**Input:**

```
arr = [3, 5, 6, 7, 9, 10], k = 4
```

**Output:**

```
4
```

**Explanation:**
We need at least 3 lucky troops since `ceil(6 / 2) = 3`. Currently, no troop is divisible by 4.

* Add 1 soldier for troop 3 → 4
* Add 2 for troop 6 → 8
* Add 1 for troop 7 → 8
  Total soldiers added = 4.

---

## Approach

1. **Count Already Lucky Troops:**

   * A troop is lucky if `arr[i] % k == 0`.
   * Count them directly.

2. **Calculate Conversion Cost:**

   * For each unlucky troop, cost to make it lucky:

     ```
     cost = k - (arr[i] % k)
     ```

3. **Determine Soldiers to Add:**

   * Sort the list of costs in ascending order.
   * Pick the smallest costs until we have enough lucky troops.

4. **Return the Sum of Picked Costs.**

---

## Pseudocode

```
n = arr.size()
target = ceil(n / 2)
alreadyLucky = 0
costs = []

for num in arr:
    if num % k == 0:
        alreadyLucky++
    else:
        costs.push(k - (num % k))

if alreadyLucky >= target:
    return 0

sort(costs)
need = target - alreadyLucky
answer = sum of first 'need' elements in costs
return answer
```

---

## C++ Implementation

```cpp
class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int target = (n + 1) / 2; // ceil(n/2)

        int alreadyLucky = 0;
        vector<int> costs;

        for (int num : arr) {
            if (num % k == 0) {
                alreadyLucky++;
            } else {
                costs.push_back(k - (num % k));
            }
        }

        if (alreadyLucky >= target) return 0;

        sort(costs.begin(), costs.end());
        int need = target - alreadyLucky;
        int soldiersAdded = 0;

        for (int i = 0; i < need; i++) {
            soldiersAdded += costs[i];
        }

        return soldiersAdded;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n log n)` (due to sorting costs)
* **Space Complexity:** `O(n)` (storing conversion costs)

---

## Key Insight

We only need to convert the cheapest `ceil(n/2) - alreadyLucky` troops to lucky ones, and sorting the costs ensures minimal total soldiers added.
