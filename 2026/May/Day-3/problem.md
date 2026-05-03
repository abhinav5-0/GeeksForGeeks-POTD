# Sort by Set Bit Count

**Difficulty:** Easy
**Accuracy:** 36.7%
**Submissions:** 55K+
**Points:** 2
**Average Time:** 20m

---

## Problem Statement

Given an array `arr[]` of integers, sort the array in **descending order** according to the **count of set bits (1s)** in the binary representation of the elements.

---

## Note

* If two numbers have the **same number of set bits**, maintain their **original relative order** (i.e., perform a **stable sort**).

---

## Examples

### Example 1

```
Input: arr[] = [5, 2, 3, 9, 4, 6, 7, 15, 32]
Output: [15, 7, 5, 3, 9, 6, 2, 4, 32]
```

**Explanation:**

Binary representations:

```
15 -> 1111
7  -> 0111
5  -> 0101
3  -> 0011
9  -> 1001
6  -> 0110
2  -> 0010
4  -> 0100
32 -> 100000
```

Sorted based on set bits (descending):

```
[15], [7], [5, 3, 9, 6], [2, 4, 32]
```

---

### Example 2

```
Input: arr[] = [1, 2, 3, 4, 5, 6]
Output: [3, 5, 6, 1, 2, 4]
```

**Explanation:**

Binary representations:

```
3 -> 0011
5 -> 0101
6 -> 0110
1 -> 0001
2 -> 0010
4 -> 0100
```

Sorted based on set bits (descending):

```
[3, 5, 6], [1, 2, 4]
```

---

## Constraints

```
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^6
```

---

## Function Signature

### C++

```cpp
class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
    }
};
```

### Java

```java
class Solution {
    public int[] sortBySetBitCount(int[] arr) {
        // code here
    }
}
```

### Python

```python
class Solution:
    def sortBySetBitCount(self, arr):
        # code here
        pass
```

---

## Notes

* Use **bit counting** (`__builtin_popcount`, `Integer.bitCount`, etc.).
* Apply **stable sorting** based on set bit count in descending order.
