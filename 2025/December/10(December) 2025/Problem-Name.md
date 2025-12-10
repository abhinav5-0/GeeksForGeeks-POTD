# Missing and Repeating — Solution (Markdown)

## 🧩 Problem Summary

You are given an array `arr[]` of size **n**, containing numbers from **1 to n**. Exactly:

* One number is **missing**.
* One number appears **twice**.

Your task: return both values → `[repeating, missing]`.

---

## ✅ Optimal Approach (O(n) time, O(1) space)

We use **mathematical properties** of sums:

Let:

* `S` = sum of numbers from `1..n`
* `S2` = sum of squares of numbers from `1..n`
* `A` = sum of elements in array
* `A2` = sum of squares of elements in array

Let:

* `x` = repeating number
* `y` = missing number

We know:

```
A  - S  = x - y         ...(1)
A2 - S2 = x^2 - y^2
        = (x - y)(x + y)   ...(2)
```

Let:

```
diff1 = x - y                (from eq. 1)
diff2 = x + y = (A2 - S2) / diff1
```

Now solve:

```
x = (diff1 + diff2) / 2
y = x - diff1
```

---

## ⏱ Complexity

* **Time:** O(n)
* **Space:** O(1)

---

## ✅ C++ Code

```cpp
class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();

        long long S = n * (n + 1) / 2;                  // sum 1..n
        long long S2 = n * (n + 1) * (2*n + 1) / 6;      // sum of squares 1..n

        long long A = 0, A2 = 0;
        for (long long x : arr) {
            A += x;
            A2 += 1LL * x * x;
        }

        long long diff1 = A - S;              // x - y
        long long diff2 = (A2 - S2) / diff1;  // x + y

        long long repeating = (diff1 + diff2) / 2;
        long long missing = repeating - diff1;

        return {(int)repeating, (int)missing};
    }
};
```

---

## 📝 Examples

### Example 1

**Input:** `[2, 2]`
**Output:** `[2, 1]`
Repeating = 2, Missing = 1

---

### Example 2

**Input:** `[1, 3, 3]`
**Output:** `[3, 2]`

---

### Example 3

**Input:** `[4, 3, 6, 2, 1, 1]`
**Output:** `[1, 5]`

---

## 🎯 Final Answer

Using sum and sum-of-squares equations, we can find the repeating and missing numbers in **O(n)** time and **O(1)** space.
