# Intersection of Two Sorted Arrays

## 🧩 Problem Statement

Given two **sorted arrays** `a[]` and `b[]`, where each array may contain duplicate elements, return the elements in the **intersection** of the two arrays in **sorted order**.

> **Note:** The intersection should contain **distinct common elements** present in both arrays.

---

## 📌 Examples

### Example 1

```
Input:  a[] = [1, 1, 2, 2, 2, 4]
        b[] = [2, 2, 4, 4]
Output: [2, 4]
Explanation: Distinct common elements are 2 and 4.
```

### Example 2

```
Input:  a[] = [1, 2]
        b[] = [3, 4]
Output: []
Explanation: No common elements.
```

### Example 3

```
Input:  a[] = [1, 2, 3]
        b[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation: All elements are common.
```

---

## ⚙️ Constraints

* `1 ≤ a.size(), b.size() ≤ 10^5`
* `-10^9 ≤ a[i], b[i] ≤ 10^9`

---

## 🚀 Approach (Two Pointer Technique)

Since both arrays are sorted, we can use the **two-pointer technique**:

1. Initialize two pointers `i = 0` and `j = 0`.
2. Traverse both arrays:

   * If `a[i] == b[j]`, add to result (avoid duplicates), move both pointers.
   * If `a[i] < b[j]`, move `i`.
   * Else move `j`.
3. Ensure only **distinct elements** are added.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n + m)`
* **Space Complexity:** `O(1)` (excluding output)

---

## 💻 Code Implementations

### 🟦 C++

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> result;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                if (result.empty() || result.back() != a[i])
                    result.push_back(a[i]);
                i++;
                j++;
            }
            else if (a[i] < b[j]) {
                i++;
            }
            else {
                j++;
            }
        }
        
        return result;
    }
};
```

---

### 🟨 Java

```java
import java.util.*;

class Solution {
    public ArrayList<Integer> intersection(int[] a, int[] b) {
        int i = 0, j = 0;
        ArrayList<Integer> result = new ArrayList<>();

        while (i < a.length && j < b.length) {
            if (a[i] == b[j]) {
                if (result.isEmpty() || result.get(result.size() - 1) != a[i]) {
                    result.add(a[i]);
                }
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
}
```

---

### 🟩 Python

```python
class Solution:
    def intersection(self, a, b):
        i, j = 0, 0
        result = []

        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                if not result or result[-1] != a[i]:
                    result.append(a[i])
                i += 1
                j += 1
            elif a[i] < b[j]:
                i += 1
            else:
                j += 1

        return result
```

---

## 🔑 Key Points

* Arrays are already sorted → use **two pointers**.
* Avoid duplicates by checking last inserted element.
* Efficient and optimal solution.
