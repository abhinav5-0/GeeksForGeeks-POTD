# Check for Power

## 🧩 Problem Statement

Given two positive integers `x` and `y`, determine if `y` is a power of `x`.

Return **true** if `y = x^k` for some integer `k ≥ 0`, otherwise return **false**.

---

## 💡 Examples

### Example 1

```
Input: x = 2, y = 8
Output: true
Explanation: 2^3 = 8
```

### Example 2

```
Input: x = 1, y = 8
Output: false
Explanation: No power of 1 equals 8
```

### Example 3

```
Input: x = 46, y = 205962976
Output: true
Explanation: 46^5 = 205962976
```

### Example 4

```
Input: x = 50, y = 312500000
Output: true
Explanation: 50^5 = 312500000
```

---

## 🔒 Constraints

* `1 ≤ x ≤ 10^3`
* `1 ≤ y ≤ 10^9`

---

## 🧠 Approach

### Method 1: Repeated Division

* Keep dividing `y` by `x`
* If at any step `y % x != 0`, return false
* If finally `y == 1`, return true

### Edge Case:

* If `x == 1`, return `y == 1`

---

## ⚡ C++ Solution

```cpp
class Solution {
public:
    bool isPower(int x, int y) {
        if (x == 1) return y == 1;
        
        while (y % x == 0) {
            y /= x;
        }
        
        return y == 1;
    }
};
```

---

## ☕ Java Solution

```java
class Solution {
    public boolean isPower(int x, int y) {
        if (x == 1) return y == 1;
        
        while (y % x == 0) {
            y /= x;
        }
        
        return y == 1;
    }
}
```

---

## 🐍 Python Solution

```python
class Solution:
    def isPower(self, x: int, y: int) -> bool:
        if x == 1:
            return y == 1
        
        while y % x == 0:
            y //= x
        
        return y == 1
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** O(logₓ(y))
* **Space Complexity:** O(1)

---

## ✅ Key Insight

A number `y` is a power of `x` if we can repeatedly divide `y` by `x` and finally reach `1`. If at any step division is not exact, then it is not a power.
