# Subset XOR — Detailed Solution (MD)

### **Problem Statement**

Given a positive integer `n`, find a subset of numbers from `1` to `n` (each number used at most once) such that:

1. The XOR of all elements in the subset is **exactly `n`**.
2. The **size** of the subset is **as large as possible**.
3. If multiple such subsets exist, choose the **lexicographically smallest**.

---

## 🔍 Key Insight

Let:

```
X = 1 ⊕ 2 ⊕ 3 ⊕ ... ⊕ n
```

Where `⊕` is bitwise XOR.

There are two cases:

### **Case 1: X == n**

The XOR of **all numbers** from `1` to `n` equals `n`.

➡️ We return the **full set**:

```
[1, 2, 3, ..., n]
```

This gives the **maximum possible size = n**.

---

### **Case 2: X != n**

We must remove **exactly one element** `missing` such that:

```
X ⊕ missing = n
```

So:

```
missing = X ⊕ n
```

Then the subset becomes:

```
[1, 2, ..., missing-1, missing+1, ..., n]
```

This is:

* Size = **n − 1** (max possible)
* **Lexicographically smallest** because we avoid removing small numbers unless required
* Question constraints ensure this always works for 1 ≤ n ≤ 1e5

---

## ✔️ XOR of First n Natural Numbers

The XOR of numbers from 1 to n follows a known pattern:

```
n % 4 == 0 → XOR = n
n % 4 == 1 → XOR = 1
n % 4 == 2 → XOR = n + 1
n % 4 == 3 → XOR = 0
```

---

## 🧪 Examples

### **Input: 4**

```
1⊕2⊕3⊕4 = 4
```

So we return all elements:

```
[1, 2, 3, 4]
```

### **Input: 3**

```
1⊕2⊕3 = 0
missing = 0 ⊕ 3 = 3
```

Return:

```
[1, 2]
```

---

## 🧠 Time Complexity

```
O(n) — constructing the subset
```

---

## 🧾 C++ Implementation

```cpp
class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        int X;
        // XOR of 1..n using pattern
        if (n % 4 == 0) X = n;
        else if (n % 4 == 1) X = 1;
        else if (n % 4 == 2) X = n + 1;
        else X = 0;

        // Case 1: XOR already equals n
        if (X == n) {
            ans.reserve(n);
            for (int i = 1; i <= n; i++) ans.push_back(i);
            return ans;
        }

        // Case 2: Remove one element
        int missing = X ^ n;

        ans.reserve(n - 1);
        for (int i = 1; i <= n; i++) {
            if (i != missing) ans.push_back(i);
        }
        return ans;
    }
};
```
