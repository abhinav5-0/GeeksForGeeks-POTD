# Sum of XOR of All Pairs

## 🟡 Difficulty: Medium

**Accuracy:** 45.14%
**Submissions:** 61K+
**Points:** 4

---

## 🧩 Problem Statement

Given an integer array `arr[]` of size `n`, compute the sum of the **bitwise XOR** for all distinct pairs of elements.

That is, consider every pair `(i, j)` such that:

```
0 ≤ i < j < n
```

Calculate:

```
(arr[i] XOR arr[j])
```

Return the total sum of XOR values for all such pairs.

---

## 📌 Examples

### Example 1

```
Input: arr[] = [7, 3, 5]
Output: 12
```

**Explanation:**

* 7 ^ 3 = 4
* 7 ^ 5 = 2
* 3 ^ 5 = 6

Sum = 4 + 2 + 6 = **12**

---

### Example 2

```
Input: arr[] = [5, 9, 7, 6]
Output: 47
```

**Explanation:**

* 5 ^ 9 = 12
* 5 ^ 7 = 2
* 5 ^ 6 = 3
* 9 ^ 7 = 14
* 9 ^ 6 = 15
* 7 ^ 6 = 1

Sum = **47**

---

### Example 3

```
Input: arr[] = [10]
Output: 0
```

**Explanation:**
No pairs exist.

---

## 🚫 Brute Force Approach

* Check all pairs
* Compute XOR for each pair

### Complexity

* Time: **O(n²)** → Too slow for large `n`

---

## ⚡ Optimized Approach (Bit Manipulation)

### 🔍 Key Idea

Instead of computing XOR for every pair, calculate contribution of each bit independently.

For each bit position (0 to 31):

* Count numbers with bit = 1 → `count1`
* Count numbers with bit = 0 → `count0 = n - count1`

Valid XOR pairs at this bit:

```
count1 × count0
```

Each contributes:

```
2^bit
```

---

## 🧮 Formula

```
Total Sum = Σ (count1 × count0 × (1 << bit))
```

---

## 🚀 C++ Solution

```cpp
class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            long long count1 = 0;

            for (int i = 0; i < n; i++) {
                if (arr[i] & (1 << bit)) {
                    count1++;
                }
            }

            long long count0 = n - count1;
            ans += count1 * count0 * (1LL << bit);
        }

        return ans;
    }
};
```

---

## 🧠 Java Solution

```java
class Solution {
    public long sumXOR(int[] arr) {
        int n = arr.length;
        long ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            long count1 = 0;

            for (int num : arr) {
                if ((num & (1 << bit)) != 0) {
                    count1++;
                }
            }

            long count0 = n - count1;
            ans += count1 * count0 * (1L << bit);
        }

        return ans;
    }
}
```

---

## 🐍 Python Solution

```python
class Solution:
    def sumXOR(self, arr):
        n = len(arr)
        ans = 0

        for bit in range(32):
            count1 = 0

            for num in arr:
                if num & (1 << bit):
                    count1 += 1

            count0 = n - count1
            ans += count1 * count0 * (1 << bit)

        return ans
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(32 × n) ≈ O(n)
* **Space Complexity:** O(1)

---

## 💡 Key Takeaways

* XOR depends on differing bits
* Count pairs instead of computing each XOR
* Use bit manipulation to reduce complexity

---

## 🧠 Intuition Summary

* Focus on bits, not numbers
* Each bit contributes independently
* Efficient counting avoids nested loops

---

✨ This is a classic example of **bit manipulation optimization** used in competitive programming.
