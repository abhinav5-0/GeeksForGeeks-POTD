# 🍬 Candy Distribution Problem

## Problem Statement

There are **n children** standing in a line. Each child has a **rating** given in an array `arr[]`.

You must distribute candies following these rules:

1. Every child must get **at least one candy**.
2. A child with a **higher rating than their immediate neighbor** must get **more candies** than that neighbor.

👉 Your task is to return the **minimum number of candies** required.

---

## Examples

### Example 1

**Input:**

```
arr = [1, 0, 2]
```

**Output:**

```
5
```

**Explanation:**

* Child 0 → 2 candies
* Child 1 → 1 candy
* Child 2 → 2 candies

---

### Example 2

**Input:**

```
arr = [1, 2, 2]
```

**Output:**

```
4
```

**Explanation:**

* Candies distributed as `[1, 2, 1]`

---

## 💡 Optimal Approach (Greedy – Two Pass)

### Step 1: Initialize

* Give **1 candy to each child** initially.

### Step 2: Left → Right Pass

* If `arr[i] > arr[i-1]`, then:

  ```
  candy[i] = candy[i-1] + 1
  ```

### Step 3: Right → Left Pass

* If `arr[i] > arr[i+1]`, then:

  ```
  candy[i] = max(candy[i], candy[i+1] + 1)
  ```

### Step 4: Sum All Candies

* Add all candy values to get the answer.

---

## ✅ Why This Works

* Ensures **both neighbors' conditions** are satisfied
* Guarantees **minimum candies**
* Efficient for large inputs

---

## ⏱ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## 📝 Key Takeaways

* Greedy strategy works best here
* Two passes handle left and right neighbor conditions cleanly
* Problem looks hard but logic is simple when broken down

---

✨ *This problem is a must-know greedy pattern for interviews and competitive programming.*
