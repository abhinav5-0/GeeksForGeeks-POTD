# 🧩 Next Smallest Palindrome

## 🔴 Difficulty: Hard

**Accuracy:** 19.63%
**Submissions:** 66K+
**Points:** 8

---

## 📘 Problem Statement

Given a number in the form of an array `num[]` containing digits from **1 to 9 (inclusive)**.
Find the **next smallest palindrome strictly larger** than the given number.

---

## 🧪 Examples

### Example 1

```
Input:  num[] = [9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2]
Output: [9, 4, 1, 8, 8, 0, 8, 8, 1, 4, 9]
```

**Explanation:**
Next smallest palindrome is **94188088149**.

---

### Example 2

```
Input:  num[] = [2, 3, 5, 4, 5]
Output: [2, 3, 6, 3, 2]
```

**Explanation:**
Next smallest palindrome is **23632**.

---

## 📌 Constraints

* (1 \leq n \leq 10^5)
* (1 \leq num[i] \leq 9)

---

## 💡 Approach

### Step 1: Check if all digits are 9

* If yes → result is `1 + (n-1 zeros) + 1`

### Step 2: Find the middle

* Use two pointers: `i = mid - 1`, `j = mid + 1`

### Step 3: Skip equal middle digits

* Move outward while digits are same

### Step 4: Decide whether to increment middle

* If left < right → need increment

### Step 5: Mirror left to right

* Copy left half to right half

### Step 6: Handle carry (if needed)

* Increment middle and propagate carry
* Mirror again

---

## ⏱️ Complexity

* **Time:** O(n)
* **Space:** O(1)

---

## 🧠 Key Idea

Palindrome banane ke liye **left half ko right me copy** karte hain.
Agar wo number bada nahi hai, toh **middle increment** karke dobara mirror karte hain.

---

## 🚀 Pseudocode

```
if all digits are 9:
    return [1, 0, 0, ..., 1]

find mid
check if left < right
mirror left to right

if increment needed:
    add carry to middle
    propagate carry to left
    mirror again
```

---

## ✨ Summary

* Mirror first
* If not greater → increment middle
* Handle carry carefully
* Works in linear time 🚀
