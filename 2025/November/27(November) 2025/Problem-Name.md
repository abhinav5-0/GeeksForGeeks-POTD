# All Subsets XOR Sum — Explanation & Solution

## 🧠 Problem Summary

Given an array `arr[]`, compute the **sum of XOR of all elements** for **every possible subset** of the array. The empty subset contributes `0`.

**Example:**

* Input: `[7, 2]`
* Subsets: `[], [7], [2], [7, 2]`
* XORs: `0, 7, 2, 7^2 = 5`
* Sum = `7 + 2 + 5 = 14`

The answer always fits in a 32-bit integer.

---

## 💡 Key Insight

Each bit position (0–31) can be treated independently because XOR works on bits.

### **Important Observation:**

If a bit is set in **any element** of the array, then that bit appears in **exactly half** of the subsets.

This gives a powerful formula:

### ✅ **Final Formula:**

[
\text{Answer} = (OR_of_all_elements) \times 2^{(n-1)}
]
Where:

* `OR_of_all_elements` = bitwise OR of the entire array
* `n` = size of array

### Why does this work?

* A bit that appears in the OR is present in at least one number
* Each such bit appears in exactly `2^(n−1)` subsets
* Summing all subsets' XOR is equivalent to OR × that factor

---

## ✔ Example Walkthrough

### Example 1

```
arr = [7, 2]
OR = 7 | 2 = 7
n = 2
Answer = 7 × 2^(2-1) = 7 × 2 = 14
```

### Example 2

```
arr = [1, 2, 3]
OR = 1|2|3 = 3
n = 3
Answer = 3 × 2^(3-1) = 3 × 4 = 12
```

---

## 🧮 Time Complexity

* OR computation: `O(n)`
* Final calculation: `O(1)`

**Total:** `O(n)` — Extremely efficient.

---

## 🧑‍💻 Final C++ Code

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int OR = 0;

        // Compute OR of all elements
        for (int x : arr) {
            OR |= x;
        }

        // Multiply by 2^(n-1)
        return OR * (1 << (n - 1));
    }
};
```

---

## ✅ Summary

* XOR of all subsets can be computed using **OR × 2^(n-1)**
* No need to iterate over all subsets
* Works efficiently up to n = 30

Let me know if you want a **Python**, **Java**, or **detailed bit‑proof** version!
