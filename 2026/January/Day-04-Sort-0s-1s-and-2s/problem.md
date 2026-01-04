# Sort 0s, 1s and 2s

**Difficulty:** Medium
**Accuracy:** 50.58%
**Submissions:** 835K+
**Points:** 4
**Average Time:** 10m

---

## Problem Statement

Given an array `arr[]` containing only `0`s, `1`s, and `2`s, sort the array in **ascending order**.

> ⚠️ Constraint: You are **not allowed** to use any built-in sort function.

---

## Examples

### Example 1

**Input:**

```
[0, 1, 2, 0, 1, 2]
```

**Output:**

```
[0, 0, 1, 1, 2, 2]
```

### Example 2

**Input:**

```
[0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
```

**Output:**

```
[0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
```

---

## Follow-up

Can you solve the problem in **one pass** using **constant extra space**?

✔️ Yes — using the **Dutch National Flag Algorithm**.

---

## Approach: Dutch National Flag Algorithm

We maintain three pointers:

* `low` → boundary for 0s
* `mid` → current element under consideration
* `high` → boundary for 2s

### Logic

* If `arr[mid] == 0` → swap with `arr[low]`, increment both `low` and `mid`
* If `arr[mid] == 1` → just increment `mid`
* If `arr[mid] == 2` → swap with `arr[high]`, decrement `high`

This ensures:

* All 0s are before `low`
* All 1s are between `low` and `mid`
* All 2s are after `high`

---

## C++ Implementation

```cpp
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)` (single traversal)
* **Space Complexity:** `O(1)` (constant extra space)

---

## Key Takeaway

This problem is a classic example of **in-place partitioning** and is frequently asked in interviews. Mastering the Dutch National Flag Algorithm helps in solving many similar problems efficiently.

---

Happy Codi
