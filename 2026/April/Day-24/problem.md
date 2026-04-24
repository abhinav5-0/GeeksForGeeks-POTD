# Buildings with Sunlight

## 🧩 Problem Statement

Given an array `arr[]` representing heights of buildings placed in a row. Sunlight falls from the **left side**.

A building receives sunlight if **all buildings to its left are shorter**.

👉 Find the total number of buildings that receive sunlight.

---

## 📌 Key Idea

* Traverse from **left to right**
* Keep track of the **maximum height seen so far**
* If current building height is **greater than or equal to max**, it gets sunlight

---

## 🧠 Algorithm

1. Initialize:

   * `count = 0`
   * `maxHeight = -∞`
2. Traverse array:

   * If `arr[i] >= maxHeight`

     * Increment count
     * Update `maxHeight`
3. Return `count`

---

## ⏱️ Complexity

* Time: `O(n)`
* Space: `O(1)`

---

## 🧪 Examples

### Example 1

```
Input: arr = [6, 2, 8, 4, 11, 13]
Output: 4
```

**Explanation:** Buildings with heights `6, 8, 11, 13` get sunlight.

---

### Example 2

```
Input: arr = [2, 5, 1, 8, 3]
Output: 3
```

**Explanation:** Buildings with heights `2, 5, 8` get sunlight.

---

### Example 3

```
Input: arr = [3, 3, 3, 1]
Output: 3
```

**Explanation:** First three buildings get sunlight.

---

## 💻 Solutions

### C++

```cpp
class Solution {
public:
    int visibleBuildings(vector<int>& arr) {
        int count = 0;
        int maxHeight = 0;
        
        for (int h : arr) {
            if (h >= maxHeight) {
                count++;
                maxHeight = h;
            }
        }
        return count;
    }
};
```

---

### Java

```java
class Solution {
    public int visibleBuildings(int[] arr) {
        int count = 0;
        int maxHeight = 0;
        
        for (int h : arr) {
            if (h >= maxHeight) {
                count++;
                maxHeight = h;
            }
        }
        return count;
    }
}
```

---

### Python

```python
class Solution:
    def visibleBuildings(self, arr):
        count = 0
        max_height = 0
        
        for h in arr:
            if h >= max_height:
                count += 1
                max_height = h
        
        return count
```

---

## ⚠️ Edge Cases

* Single building → always gets sunlight
* Strictly decreasing heights → only first building gets sunlight
* Equal heights → all equal or increasing ones count

---

## 🚀 Summary

* Use a **running maximum** approach
* Simple one-pass greedy solution
* Very common interview problem 🔥
