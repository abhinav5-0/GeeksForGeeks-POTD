# Opposite Sign Pair Reduction

**Difficulty:** Medium
**Accuracy:** 50.06%
**Submissions:** 55K+
**Points:** 4
**Average Time:** 30m

---

## Problem Statement

Given an array `arr[]`, return the final array by repeatedly applying the following operation from left to right until no more valid operations can be performed.

### Operation Rules

If two adjacent elements have **opposite signs**:

* If their absolute values are different:

  * Remove both elements.
  * Insert the element with the **greater absolute value**, preserving its sign.

* If their absolute values are equal:

  * Remove both elements.
  * Do **not** insert anything.

---

## Examples

### Example 1

```
Input: arr[] = [10, -5, -8, 2, -5]
Output: [10]
```

**Explanation:**

* At index 0: 10 is positive.
* At index 1: -5 has smaller absolute value → replaced by 10.
* At index 2: -8 has smaller absolute value → replaced by 10.
* At index 3: 2 has same sign → remains.
* At index 4: -5 has greater absolute value than 2 → replaced by 5.
* Now -5 vs 10 → 10 remains.

---

### Example 2

```
Input: arr[] = [5, -5, -2, -10]
Output: [-2, -10]
```

**Explanation:**

* 5 and -5 cancel out (equal absolute values).
* Remaining elements have same sign.

---

### Example 3

```
Input: arr[] = [-20, 1, 20]
Output: []
```

**Explanation:**

* -20 and 1 → -20 remains.
* -20 and 20 cancel out.

---

## Constraints

* `1 ≤ arr.size() ≤ 10^5`
* `-10000 ≤ arr[i] ≤ 10000`
* `arr[i] ≠ 0`

---

## Approach

Use a **stack-based simulation**:

* Traverse the array.
* For each element:

  * While stack top has opposite sign:

    * Compare absolute values.
    * Apply rules (remove, replace, or cancel).
* Push remaining elements to stack.

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;
        
        for (int x : arr) {
            while (!st.empty() && st.back() * x < 0) {
                if (abs(st.back()) > abs(x)) {
                    x = st.back();
                    st.pop_back();
                } else if (abs(st.back()) < abs(x)) {
                    st.pop_back();
                } else {
                    st.pop_back();
                    x = 0;
                    break;
                }
            }
            if (x != 0) st.push_back(x);
        }
        
        return st;
    }
};
```

---

## Java Solution

```java
class Solution {
    public int[] reducePairs(int[] arr) {
        Stack<Integer> st = new Stack<>();
        
        for (int x : arr) {
            while (!st.isEmpty() && st.peek() * x < 0) {
                if (Math.abs(st.peek()) > Math.abs(x)) {
                    x = st.pop();
                } else if (Math.abs(st.peek()) < Math.abs(x)) {
                    st.pop();
                } else {
                    st.pop();
                    x = 0;
                    break;
                }
            }
            if (x != 0) st.push(x);
        }
        
        return st.stream().mapToInt(i -> i).toArray();
    }
}
```

---

## Python Solution

```python
class Solution:
    def reducePairs(self, arr):
        st = []
        
        for x in arr:
            while st and st[-1] * x < 0:
                if abs(st[-1]) > abs(x):
                    x = st.pop()
                elif abs(st[-1]) < abs(x):
                    st.pop()
                else:
                    st.pop()
                    x = 0
                    break
            if x != 0:
                st.append(x)
        
        return st
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## Key Insight

This
