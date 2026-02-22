# Count Subarrays with Given XOR

**Difficulty:** Medium
**Accuracy:** 58.86%
**Submissions:** 75K+
**Points:** 4

---

## Problem Statement

Given an array of integers `arr[]` and a number `k`, count the number of subarrays having **XOR** of their elements equal to `k`.

> **Note:** It is guaranteed that the total count will fit within a 32-bit integer.

---

## Examples

### Example 1

**Input:**

```
arr[] = [4, 2, 2, 6, 4]
k = 6
```

**Output:**

```
4
```

**Explanation:**
The subarrays having XOR of their elements as 6 are:

* [4, 2]
* [4, 2, 2, 6, 4]
* [2, 2, 6]
* [6]

Hence, the answer is 4.

---

### Example 2

**Input:**

```
arr[] = [5, 6, 7, 8, 9]
k = 5
```

**Output:**

```
2
```

**Explanation:**
The subarrays having XOR of their elements as 5 are:

* [5]
* [5, 6, 7, 8, 9]

Hence, the answer is 2.

---

### Example 3

**Input:**

```
arr[] = [1, 1, 1, 1]
k = 0
```

**Output:**

```
4
```

**Explanation:**
The subarrays are:

* [1, 1]
* [1, 1]
* [1, 1]
* [1, 1, 1, 1]

---

## Constraints

* (1 \leq arr.size() \leq 10^5)
* (0 \leq arr[i] \leq 10^5)
* (0 \leq k \leq 10^5)

---

## Function Signature (C++)

```cpp
class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
    }
};
```

---

## Expected Approach

* Use **Prefix XOR** technique.
* Use a **Hash Map (unordered_map)** to store frequency of prefix XOR values.
* Time Complexity: **O(N)**
* Space Complexity: **O(N)**

---

## Tags

`Hashing` `Prefix XOR` `Arrays` `Bit Manipulation`
