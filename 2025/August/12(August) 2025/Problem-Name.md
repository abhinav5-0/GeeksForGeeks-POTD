# Shop in Candy Store

**Difficulty:** Medium
**Accuracy:** 45.43%
**Points:** 4

---

## Problem Statement

In a candy store, there are different types of candies available and `prices[i]` represent the price of the i-th type of candy. You are now provided with an attractive offer:

> For every candy you buy from the store, you can get up to `k` other different candies for free.

Find the **minimum** and **maximum** amount of money needed to buy **all** the candies.

**Note:** In both cases, you must take the **maximum number** of free candies possible during each purchase.

---

### Example 1

**Input:**

```
prices = [3, 2, 1, 4], k = 2
```

**Output:**

```
[3, 7]
```

**Explanation:**

* **Minimum cost:** Buy candy worth 1, take candies worth 3 and 4 for free. Then buy candy worth 2. Cost = 1 + 2 = 3.
* **Maximum cost:** Buy candy worth 4, take candies worth 1 and 2 for free. Then buy candy worth 3. Cost = 4 + 3 = 7.

---

### Example 2

**Input:**

```
prices = [3, 2, 1, 4, 5], k = 4
```

**Output:**

```
[1, 5]
```

**Explanation:**

* **Minimum cost:** Buy candy worth 1, get all others free.
* **Maximum cost:** Buy candy worth 5, get all others free.

---

## Constraints

* 1 ≤ `prices.size()` ≤ 10^5
* 0 ≤ k ≤ `prices.size()`
* 1 ≤ `prices[i]` ≤ 10^4

---

## Approach

We solve this using a **greedy strategy** with sorting:

### Minimum Cost

* Sort prices in ascending order.
* Always buy the cheapest available candy.
* Take the `k` most expensive remaining candies for free.
* Use two pointers:

  * `i` from the start (buying)
  * `j` from the end (free candies)

### Maximum Cost

* Sort prices in ascending order.
* Always buy the most expensive available candy.
* Take the `k` cheapest remaining candies for free.
* Use two pointers:

  * `i` from the end (buying)
  * `j` from the start (free candies)

---

## Complexity

* Sorting: **O(n log n)**
* Greedy loops: **O(n)**
* **Total:** O(n log n)
* Space: **O(1)** (in-place sorting)

---

## Code Implementation

```cpp
class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();

        // Minimum cost calculation
        int minCost = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minCost += prices[i];
            i++;
            j -= k; // take k expensive ones for free
        }

        // Maximum cost calculation
        int maxCost = 0;
        i = n - 1, j = 0;
        while (j <= i) {
            maxCost += prices[i];
            i--;
            j += k; // take k cheapest ones for free
        }

        return {minCost, maxCost};
    }
};
```

---

## Dry Run Example

**Input:**

```
prices = [3, 2, 1, 4], k = 2
```

**Sorted:** `[1, 2, 3, 4]`

**Min Cost:**

* Buy 1 (take 4, 3 for free), remaining: \[2] → Buy 2 → Cost = 3

**Max Cost:**

* Buy 4 (take 1, 2 for free), remaining: \[3] → Buy 3 → Cost = 7

**Output:** `[3, 7]` ✅
