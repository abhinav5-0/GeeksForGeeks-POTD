# Common in 3 Sorted Arrays

## Problem

Given three sorted arrays in **non-decreasing order**, return all common elements in **non-decreasing order** across these arrays.

* Ignore duplicates
* Include each common element only once in the output

---

## Examples

### Example 1

**Input:**
a = [1, 5, 5, 10, 20, 40, 80]
b = [6, 7, 20, 80, 100]
c = [3, 4, 15, 20, 30, 70, 80, 120]

**Output:**
[20, 80]

**Explanation:**
20 and 80 appear in all three arrays.

---

### Example 2

**Input:**
a = [1, 2, 3, 4, 5]
b = [6, 7]
c = [8, 9, 10]

**Output:**
[]

**Explanation:**
No common elements exist.

---

### Example 3

**Input:**
a = [1, 1, 1, 2, 2, 2]
b = [1, 1, 2, 2, 2]
c = [1, 1, 1, 2, 2, 2, 2]

**Output:**
[1, 2]

**Explanation:**
Ignoring duplicates, 1 and 2 are common in all arrays.

---

## Constraints

* 1 ≤ a.size(), b.size(), c.size() ≤ 10^5
* -10^5 ≤ a[i], b[i], c[i] ≤ 10^5

---

## Approach (Three Pointer Technique)

* Use three pointers i, j, k for arrays a, b, c
* Compare elements at these pointers:

  * If all equal → add to result and move all pointers
  * Else move the pointer with the smallest value
* Skip duplicates while moving pointers

**Time Complexity:** O(n1 + n2 + n3)
**Space Complexity:** O(1)

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> result;

        while (i < a.size() && j < b.size() && k < c.size()) {
            if (a[i] == b[j] && b[j] == c[k]) {
                if (result.empty() || result.back() != a[i])
                    result.push_back(a[i]);
                i++; j++; k++;
            }
            else if (a[i] < b[j]) i++;
            else if (b[j] < c[k]) j++;
            else k++;
        }

        return result;
    }
};
```

---

## Java Solution

```java
import java.util.*;

class Solution {
    public List<Integer> commonElements(int[] a, int[] b, int[] c) {
        int i = 0, j = 0, k = 0;
        List<Integer> result = new ArrayList<>();

        while (i < a.length && j < b.length && k < c.length) {
            if (a[i] == b[j] && b[j] == c[k]) {
                if (result.isEmpty() || result.get(result.size() - 1) != a[i])
                    result.add(a[i]);
                i++; j++; k++;
            }
            else if (a[i] < b[j]) i++;
            else if (b[j] < c[k]) j++;
            else k++;
        }

        return result;
    }
}
```

---

## Python Solution

```python
class Solution:
    def commonElements(self, a, b, c):
        i = j = k = 0
        result = []

        while i < len(a) and j < len(b) and k < len(c):
            if a[i] == b[j] == c[k]:
                if not result or result[-1] != a[i]:
                    result.append(a[i])
                i += 1
                j += 1
                k += 1
            elif a[i] < b[j]:
                i += 1
            elif b[j] < c[k]:
                j += 1
            else:
                k += 1

        return result
```

---

## Key Points

* Arrays are already sorted → use two/three pointer technique
* Avoid duplicates using last inserted element check
* Efficient compared to brute force approach
