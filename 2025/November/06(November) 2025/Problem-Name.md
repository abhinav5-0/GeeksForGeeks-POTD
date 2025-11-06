## 🧩 Problem: Ways To Tile A Floor

**Difficulty:** Medium
**Accuracy:** 32.31%
**Points:** 4

---

### 🧠 Problem Statement

Given a floor of dimensions **2 × n** and tiles of dimensions **2 × 1**, the task is to find the number of ways the floor can be tiled. A tile can either be placed **horizontally** (1 × 2) or **vertically** (2 × 1).

Two tiling arrangements are considered different if the placement of at least one tile differs.

---

### 🧮 Examples

#### Example 1:

**Input:** `n = 3`
**Output:** `3`

**Explanation:**
We can tile in the following ways:

1. Place all 3 tiles vertically.
2. Place the first tile vertically and remaining 2 tiles horizontally.
3. Place the first 2 tiles horizontally and the remaining 1 tile vertically.

#### Example 2:

**Input:** `n = 4`
**Output:** `5`

**Explanation:**
We can tile in the following ways:

1. All 4 vertical
2. All 4 horizontal
3. First 2 vertical, remaining 2 horizontal
4. First 2 horizontal, remaining 2 vertical
5. Corner 2 vertical, middle 2 horizontal

---

### 📏 Constraints

* 1 ≤ n ≤ 45

---

### 💡 Intuition

This problem follows a **Fibonacci-like recurrence relation**.

If we consider:

* Placing one **vertical** tile on the left → Remaining floor is 2 × (n−1)
* Placing two **horizontal** tiles stacked → Remaining floor is 2 × (n−2)

Hence,
[
numberOfWays(n) = numberOfWays(n−1) + numberOfWays(n−2)
]

---

### ⚙️ Base Cases

* `n = 1` → 1 way (one vertical tile)
* `n = 2` → 2 ways (two vertical or two horizontal tiles)

---

### ✅ C++ Solution

```cpp
class Solution {
public:
    int numberOfWays(int n) {
        if (n <= 2)
            return n;
        
        int prev2 = 1, prev1 = 2, curr;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
```

---

### 🔍 Example Dry Run

**Input:** `n = 4`

| i | prev2 | prev1 | curr |
| - | ----- | ----- | ---- |
| 3 | 1     | 2     | 3    |
| 4 | 2     | 3     | 5    |

✅ **Output:** 5

---

### 🧾 Time & Space Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

---

### 🏁 Summary

| Concept      | Description                       |
| ------------ | --------------------------------- |
| Problem Type | Dynamic Programming               |
| Formula      | `ways(n) = ways(n−1) + ways(n−2)` |
| Pattern      | Fibonacci Sequence                |
| Base Cases   | `ways(1)=1`, `ways(2)=2`          |
