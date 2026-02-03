# Stock Buy and Sell – Max One Transaction Allowed

## Problem Statement

You are given an array `prices[]` of non-negative integers where `prices[i]` represents the stock price on the `i-th` day.

Your task is to find the **maximum profit** you can achieve by doing **at most one transaction**.

> A transaction consists of **one buy and one sell**.
> You **must buy before you sell**.
> If it is not possible to make any profit, return **0**.

---

## Examples

### Example 1

**Input:**

```
prices = [7, 10, 1, 3, 6, 9, 2]
```

**Output:**

```
8
```

**Explanation:**
Buy on day 2 at price `1` and sell on day 5 at price `9`.
Profit = `9 - 1 = 8`

---

### Example 2

**Input:**

```
prices = [7, 6, 4, 3, 1]
```

**Output:**

```
0
```

**Explanation:**
Prices are in decreasing order, so no profitable transaction is possible.

---

### Example 3

**Input:**

```
prices = [1, 3, 6, 9, 11]
```

**Output:**

```
10
```

**Explanation:**
Buy at price `1` and sell at price `11`.
Profit = `11 - 1 = 10`

---

## Constraints

* `1 ≤ prices.size() ≤ 10^5`
* `0 ≤ prices[i] ≤ 10^4`

---

## Key Insight

To maximize profit with only one transaction:

* Track the **minimum price so far** while iterating
* At each day, calculate potential profit if sold today
* Keep updating the **maximum profit**

This ensures an efficient solution in **O(n)** time.

---

## Difficulty

**Easy**

## Accuracy

~49%

## Average Time

~10 minutes
