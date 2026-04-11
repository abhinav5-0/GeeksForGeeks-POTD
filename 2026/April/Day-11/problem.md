# Count Increasing Subarrays

## 🧩 Problem Statement

Given an array `arr[]` of integers, count the number of subarrays in `arr[]` which are **strictly increasing** and have size **greater than or equal to 2**.

* A **subarray** is a contiguous part of the array.
* A subarray is **strictly increasing** if each element is greater than its previous element.

---

## 📌 Examples

### Example 1

```
Input: arr[] = [1, 4, 5, 3, 7, 9]
Output: 6
```

**Explanation:**
Strictly increasing subarrays are:

* [1, 4]
* [1, 4, 5]
* [4, 5]
* [3, 7]
* [3, 7, 9]
* [7, 9]

---

### Example 2

```
Input: arr[] = [1, 3, 3, 2, 3, 5]
Output: 4
```

**Explanation:**
Strictly increasing subarrays are:

* [1, 3]
* [2, 3]
* [2, 3, 5]
* [3, 5]

---

### Example 3

```
Input: arr[] = [2, 2, 2, 2]
Output: 0
```

**Explanation:**
No strictly increasing subarray exists.

---

## ⚙️ Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `1 ≤ arr[i] ≤ 10^7`

---

## 🚀 Approach

### 🔹 Key Idea

* Traverse the array and track the length of the current increasing subarray.
* If `arr[i] > arr[i-1]`, increase the current length.
* Otherwise, reset the length.
* For each increasing segment of length `L`, number of valid subarrays = `(L * (L - 1)) / 2`.

---

## 🧠 Algorithm

1. Initialize:

   * `count = 0`
   * `len = 1`
2. Traverse array from index `1` to `n-1`:

   * If `arr[i] > arr[i-1]`:

     * `len++`
   * Else:

     * Add `(len * (len - 1)) / 2` to `count`
     * Reset `len = 1`
3. After loop, add remaining contribution.
4. Return `count`

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## 💻 Code Implementations

### 🟦 C++

```cpp
class Solution {
public:
    int countIncreasing(vector<int>& arr) {
        long long count = 0;
        long long len = 1;
        int n = arr.size();

        for(int i = 1; i < n; i++) {
            if(arr[i] > arr[i-1]) {
                len++;
            } else {
                count += (len * (len - 1)) / 2;
                len = 1;
            }
        }

        count += (len * (len - 1)) / 2;
        return count;
    }
};
```

---

### 🟨 Java

```java
class Solution {
    public int countIncreasing(int[] arr) {
        long count = 0;
        long len = 1;

        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > arr[i-1]) {
                len++;
            } else {
                count += (len * (len - 1)) / 2;
                len = 1;
            }
        }

        count += (len * (len - 1)) / 2;
        return (int)count;
    }
}
```

---

### 🟩 Python

```python
class Solution:
    def countIncreasing(self, arr):
        count = 0
        length = 1

        for i in range(1, len(arr)):
            if arr[i] > arr[i-1]:
                length += 1
            else:
                count += (length * (length - 1)) // 2
                length = 1

        count += (length * (length - 1)) // 2
        return count
```

---

## ✅ Summary

* Count lengths of increasing segments.
* Use formula `(L * (L - 1)) / 2`.
* Efficient linear scan.

---

✨
