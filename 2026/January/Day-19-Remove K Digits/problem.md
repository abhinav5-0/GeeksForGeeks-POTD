# Remove K Digits

**Difficulty:** Medium
**Accuracy:** 26.8%
**Problem Statement:**

You are given a non-negative integer `s` represented as a string and an integer `k`. Remove **exactly `k` digits** from the string so that the resulting number is the **smallest possible**, while **maintaining the relative order** of the remaining digits.

### Important Notes

* The resulting number **must not contain leading zeros**.
* If all digits are removed, return **"0"**.

---

## 🔍 Example

**Input:**

```
s = "4325043", k = 3
```

**Output:**

```
2043
```

**Explanation:**
Removing digits `4`, `3`, and `5` gives the smallest possible number `2043`.

---

## 💡 Approach: Greedy + Monotonic Stack

To obtain the smallest number:

* We want **smaller digits to appear as early as possible**.
* If a digit is **larger than the digit coming after it**, removing the larger digit helps minimize the number.

### Strategy

1. Use a **stack** (or string as stack) to build the result.
2. Traverse each digit in the string:

   * While the stack is **not empty**, `k > 0`, and the **top of the stack is greater than the current digit**, remove (pop) the stack top.
   * Push the current digit onto the stack.
3. If `k > 0` after traversal, remove digits from the **end** (largest impact least).
4. Remove **leading zeros** from the final result.
5. If the result is empty, return **"0"**.

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

Where `n` is the length of string `s`.

---

## 🧠 Key Observations

* This is a **classic greedy problem**.
* A **monotonic increasing stack** ensures minimal lexicographical order.
* Removing digits from the **left** is usually more impactful than the right.

---

## ✅ Edge Cases

* All digits removed → return `"0"`
* Number with leading zeros after removals → strip zeros
* Very large input (`|s| ≤ 10^6`) → stack-based solution is efficient

---

## 🚀 Summary

Using a greedy approach with a stack guarantees the smallest possible number after removing `k` digits, while maintaining order and handling leading zeros correctly.

This approach is optimal and works efficiently even for very large inputs.

---

✨ **Ready for implementation in C++ / Java / Python when you need it!**
