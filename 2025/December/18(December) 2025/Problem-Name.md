# Sort in Specific Order

## 🧩 Problem Statement

Given an array `arr[]` of positive integers, sort it such that:

* The **first part** of the array contains **odd numbers sorted in descending order**.
* The **remaining part** contains **even numbers sorted in ascending order**.

---

## 📌 Examples

### Example 1

**Input:**

```
arr[] = [1, 2, 3, 5, 4, 7, 10]
```

**Output:**

```
[7, 5, 3, 1, 2, 4, 10]
```

**Explanation:**

* Odd numbers → `7, 5, 3, 1` (descending)
* Even numbers → `2, 4, 10` (ascending)

---

### Example 2

**Input:**

```
arr[] = [0, 4, 5, 3, 7, 2, 1]
```

**Output:**

```
[7, 5, 3, 1, 0, 2, 4]
```

---

## ⚙️ Approach

1. Traverse the array and separate **odd** and **even** numbers.
2. Sort:

   * Odd numbers in **descending order**
   * Even numbers in **ascending order**
3. Place all odd numbers first, followed by even numbers.

---

## 💻 C++ Implementation

```cpp
class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> odd, even;

        // Separate odd and even numbers
        for (int x : arr) {
            if (x % 2 == 0)
                even.push_back(x);
            else
                odd.push_back(x);
        }

        // Sort odds in descending order
        sort(odd.begin(), odd.end(), greater<int>());
        
        // Sort evens in ascending order
        sort(even.begin(), even.end());

        // Merge back into arr
        int idx = 0;
        for (int x : odd) arr[idx++] = x;
        for (int x : even) arr[idx++] = x;
    }
};
```

---

## ⏱ Complexity Analysis

* **Time Complexity:** `O(n log n)`
* **Space Complexity:** `O(n)`

---

## ✅ Key Notes

* Stable ordering between odd and even is **not required**.
* Handles large constraints up to `10^5` efficiently.

---

✨ *This solution is optimized, readable, and fully compliant with GFG constraints.*

