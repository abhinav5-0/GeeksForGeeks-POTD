# Two Equal Sum Subarrays

## 🟢 Problem Statement

Given an array of integers `arr[]`, return **true** if it is possible to split it into two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. Otherwise, return **false**.

---

## 📌 Examples

### Example 1

```
Input: arr[] = [1, 2, 3, 4, 5, 5]
Output: true
```

**Explanation:**
We can divide the array into `[1, 2, 3, 4]` and `[5, 5]`.
Sum of both subarrays = 10.

### Example 2

```
Input: arr[] = [4, 3, 2, 1]
Output: false
```

**Explanation:**
We cannot divide the array into two subarrays with equal sum.

---

## ⚙️ Constraints

* (1 \leq arr.size() \leq 10^5)
* (1 \leq arr[i] \leq 10^6)

---

## 💡 Approach

1. Compute total sum of the array.
2. If total sum is **odd**, return false.
3. Find prefix sum while iterating.
4. If at any point prefix sum equals `totalSum / 2`, return true.

---

## ⏱️ Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

---

## 🧪 Dry Run

For `arr = [1, 2, 3, 4, 5, 5]`

| Index | Element | Prefix Sum |
| ----- | ------- | ---------- |
| 0     | 1       | 1          |
| 1     | 2       | 3          |
| 2     | 3       | 6          |
| 3     | 4       | 10 ✅       |

Target = 20 / 2 = 10 → Found ✔️

---

## 🚀 Key Insight

You just need to find a point where the prefix sum equals half of the total sum.
