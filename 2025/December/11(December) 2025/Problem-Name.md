# Missing and Repeating Number

**Difficulty:** Easy
**Accuracy:** 24.83%
**Points:** 2

Given an unsorted array `arr[]` of size `n`, containing elements from the range `1` to `n`, where **one number is missing** and **another number occurs twice**, find both numbers.

---

## 🔍 Problem Explanation

You are given an array of size `n` where:

* All elements are in the range `1` to `n`
* Exactly **one number repeats twice**
* Exactly **one number is missing**

Your task: **Return `[repeating, missing]`**.

---

## ✅ Examples

### Example 1

```
Input: arr = [2, 2]
Output: [2, 1]
```

Repeating = 2, Missing = 1

### Example 2

```
Input: arr = [1, 3, 3]
Output: [3, 2]
```

Repeating = 3, Missing = 2

### Example 3

```
Input: arr = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
```

Repeating = 1, Missing = 5

---

## 🚀 Efficient Approach (Math-Based)

We use formulas:

* Sum of first `n` natural numbers: `S = n*(n+1)/2`
* Sum of squares: `P = n*(n+1)*(2n+1)/6`

Let:

* Repeating = `R`
* Missing = `M`
* `sum_arr` = sum of array elements
* `sum_sq_arr` = sum of squares of array elements

We get:

```
R - M = sum_arr - S
R^2 - M^2 = sum_sq_arr - P  → (R - M)(R + M)
```

Now solve for `R` and `M`.

---

## 💡 C++ Code (Optimized)

```cpp
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();

        long long S = n * (n + 1) / 2;
        long long P = n * (n + 1) * (2 * n + 1) / 6;
        long long sum_arr = 0, sum_sq_arr = 0;

        for (long long x : arr) {
            sum_arr += x;
            sum_sq_arr += 1LL * x * x;
        }

        long long diff = sum_arr - S;               // R - M
        long long sq_diff = sum_sq_arr - P;         // R^2 - M^2

        long long sumRM = sq_diff / diff;           // R + M

        long long R = (diff + sumRM) / 2;
        long long M = sumRM - R;

        return {(int)R, (int)M};
    }
};
```

---

## ⏱️ Complexity

* **Time:** O(n)
* **Space:** O(1)

---

Let me know if you want the **XOR-based solution**, **frequency-based solution**, or **more examples**!
