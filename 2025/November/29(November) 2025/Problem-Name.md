# Count Set Bits (1 to n) — Efficient Solution

### **Problem Summary**

Given an integer `n`, find the total number of set bits (1s) in the binary representation of **all numbers from 1 to n**.

### **Constraints**

* `1 ≤ n ≤ 10^8`
* Naive O(n log n) is too slow → Must use **bit patterns**.

---

# 🔥 Optimal Approach (O(log n)) — Brian Kernighan + Pattern Logic

The number of set bits from 1 to n follows a recurring pattern based on powers of 2.

### **Key Observations**

For any power of two: `2^x`

* Half numbers have MSB set
* Remaining follow repetition pattern

We use:

1. **Largest power of 2 ≤ n**
2. **Bits contributed by MSB**
3. **Bits from remaining numbers**
4. Recurse on remaining part

Formula components:

* Let `x = log2(largest power of 2 ≤ n)`
* `power = 1 << x`

### **Total set bits from 1 to n**:

```
1. bits from MSB positions = (n - power + 1)
2. bits from full cycles before MSB = x * (power / 2)
3. recursively count remaining = f(n - power)
```

---

# ✅ C++ Implementation

```cpp
class Solution {
public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // Largest power of 2 <= n
        int x = log2(n);
        int power = 1 << x;

        // 1. Count of MSB set bits from power to n
        int msbBits = n - power + 1;

        // 2. Bits from previous full cycles
        int bitsBefore = x * (power >> 1);

        // 3. Recursively compute remaining part
        int rest = countSetBits(n - power);

        return msbBits + bitsBefore + rest;
    }
};
```

---

# ✔ Example Walkthrough (n = 17)

Largest power ≤ 17 is 16 (2⁴)

* x = 4
* power = 16

```
MSB bits = 17 - 16 + 1 = 2
Bits from cycles = 4 * (16/2) = 32
Remaining = f(1)
```

`f(1)` returns 1 → total = 32 + 2 + 1 = **35**

---

# 🎯 Final Answer

This solution runs in **O(log n)** and is efficient for n up to 10⁸.
