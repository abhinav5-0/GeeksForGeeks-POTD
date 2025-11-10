# Stock Buy and Sell with Cooldown

**Difficulty:** Medium
**Accuracy:** 51.65%
**Points:** 4
**Average Time:** 20m

---

## 🧩 Problem Statement

Given an array `arr[]`, where the *i-th* element represents the price of a stock on the *i-th* day (all prices are non-negative integers). Find the **maximum profit** you can make by buying and selling stocks such that after selling a stock, you cannot buy again on the next day (i.e., there is a one-day cooldown).

---

## 🧠 Example

### Example 1:

**Input:** `arr[] = [0, 2, 1, 2, 3]`
**Output:** `3`
**Explanation:**

* Buy on day 1 (price 0), sell on day 2 (price 2) → Profit = 2
* Cooldown on day 3
* Buy on day 4 (price 2), sell on day 5 (price 3) → Profit = 1
  ✅ **Total Profit = 3**

### Example 2:

**Input:** `arr[] = [3, 1, 6, 1, 2, 4]`
**Output:** `7`
**Explanation:**

* Buy on day 2 (price 1), sell on day 3 (price 6) → Profit = 5
* Cooldown on day 4
* Buy on day 5 (price 2), sell on day 6 (price 4) → Profit = 2
  ✅ **Total Profit = 7**

---

## ⚙️ Constraints

* 1 ≤ `arr.size()` ≤ 10⁵
* 1 ≤ `arr[i]` ≤ 10⁴

---

## 💡 Approach (Dynamic Programming)

We maintain **three states** for each day `i`:

1. `buy[i]` → Maximum profit when we **hold a stock** on day `i`.
2. `sell[i]` → Maximum profit when we **just sold a stock** on day `i`.
3. `cool[i]` → Maximum profit when we are **in cooldown** (i.e., sold the previous day).

### State Transitions:

* **Buy today:**
  `buy[i] = max(buy[i-1], cool[i-1] - arr[i])`

* **Sell today:**
  `sell[i] = buy[i-1] + arr[i]`

* **Cooldown today:**
  `cool[i] = max(cool[i-1], sell[i-1])`

### Final Answer:

`max(sell[n-1], cool[n-1])`

(We cannot end with a `buy` state because that means a stock is still unsold.)

---

## 🧮 Code Implementation

### ✅ C++ Solution (DP with O(n) space)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> buy(n, 0), sell(n, 0), cool(n, 0);

        buy[0] = -arr[0];
        sell[0] = 0;
        cool[0] = 0;

        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], cool[i-1] - arr[i]);
            sell[i] = buy[i-1] + arr[i];
            cool[i] = max(cool[i-1], sell[i-1]);
        }

        return max(sell[n-1], cool[n-1]);
    }
};
```

---

### 🚀 Optimized C++ Solution (O(1) space)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if (arr.empty()) return 0;

        int buy = -arr[0], sell = 0, cool = 0;

        for (int i = 1; i < arr.size(); i++) {
            int prevBuy = buy;
            buy = max(buy, cool - arr[i]);
            cool = max(cool, sell);
            sell = prevBuy + arr[i];
        }

        return max(sell, cool);
    }
};
```

---

## 🔍 Dry Run Example

**Input:** `[3, 1, 6, 1, 2, 4]`

| Day | Price | buy | sell | cool |
| --- | ----- | --- | ---- | ---- |
| 0   | 3     | -3  | 0    | 0    |
| 1   | 1     | 0   | -2   | 0    |
| 2   | 6     | 0   | 6    | 0    |
| 3   | 1     | -1  | 1    | 6    |
| 4   | 2     | 4   | 1    | 6    |
| 5   | 4     | 4   | 8    | 6    |

✅ **Maximum Profit = 8**

---

## 🏁 Summary

* Use DP with three states: `buy`, `sell`, `cool`.
* Transition based on previous day’s states.
* Time Complexity: **O(n)**
* Space Complexity: **O(1)** (optimized)

---

**Result:** Efficient dynamic programming approach to maximize stock profit with cooldown constraint.
