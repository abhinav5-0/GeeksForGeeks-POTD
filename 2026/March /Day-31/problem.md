# Buy Stock with Transaction Fee

## 🧾 Problem Statement

You are given an array `arr[]`, where `arr[i]` is the price of a given stock on the **i-th day**, and an integer `k` represents a **transaction fee**.

Your task is to find the **maximum profit** you can achieve.

* You may complete as many transactions as you like.
* However, you must pay the transaction fee for each transaction.

> ⚠️ **Note:** You cannot engage in multiple transactions simultaneously (i.e., you must sell the stock before buying again).

---

## 📥 Examples

### Example 1

**Input:**

```
arr[] = [6, 1, 7, 2, 8, 4], k = 2
```

**Output:**

```
8
```

**Explanation:**

* Buy on day 2 and sell on day 3 → Profit = 7 - 1 - 2 = 4
* Buy on day 4 and sell on day 5 → Profit = 8 - 2 - 2 = 4
* Total Profit = 4 + 4 = 8

---

### Example 2

**Input:**

```
arr[] = [7, 1, 5, 3, 6, 4], k = 1
```

**Output:**

```
5
```

**Explanation:**

* Buy on day 2 and sell on day 3 → Profit = 5 - 1 - 1 = 3
* Buy on day 4 and sell on day 5 → Profit = 6 - 3 - 1 = 2
* Total Profit = 3 + 2 = 5

---

## 📌 Constraints

* `1 ≤ arr.size() ≤ 10^6`
* `1 ≤ arr[i] ≤ 10^6`
* `0 ≤ k ≤ 10^6`

---

## 💡 Approach (Dynamic Programming)

We maintain two variables:

* `hold` → Maximum profit when holding a stock
* `cash` → Maximum profit when not holding a stock

### Transition:

```
hold = max(hold, cash - price)
cash = max(cash, hold + price - fee)
```

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## 🚀 Implementation

### C++

```cpp
class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        int hold = -arr[0];
        int cash = 0;

        for(int i = 1; i < arr.size(); i++) {
            hold = max(hold, cash - arr[i]);
            cash = max(cash, hold + arr[i] - k);
        }

        return cash;
    }
};
```

---

### Java

```java
class Solution {
    public int maxProfit(int[] arr, int k) {
        int hold = -arr[0];
        int cash = 0;

        for(int i = 1; i < arr.length; i++) {
            hold = Math.max(hold, cash - arr[i]);
            cash = Math.max(cash, hold + arr[i] - k);
        }

        return cash;
    }
}
```

---

### Python

```python
class Solution:
    def maxProfit(self, arr, k):
        hold = -arr[0]
        cash = 0

        for i in range(1, len(arr)):
            hold = max(hold, cash - arr[i])
            cash = max(cash, hold + arr[i] - k)

        return cash
```

---

## ✅ Key Insight

* Always decide whether to **buy**, **sell**, or **skip** at each step.
* The transaction fee is applied **only when selling**.
