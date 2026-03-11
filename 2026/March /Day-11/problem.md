# Sum of Subarray Minimums

**Difficulty:** Medium
**Accuracy:** 46.92%
**Submissions:** 38K+
**Points:** 4
**Average Time:** 30m

---

## Problem Statement

Given an array `arr[]` of positive integers, find the **total sum of the minimum elements of every possible subarray**.

> **Note:** It is guaranteed that the total sum will fit within a **32-bit unsigned integer**.

---

## Examples

### Example 1

**Input**

```
arr[] = [10, 20]
```

**Output**

```
40
```

**Explanation**
Subarrays are `[10]`, `[20]`, `[10, 20]`.
Minimums are `10`, `20`, `10`.
Sum = `10 + 20 + 10 = 40`.

---

### Example 2

**Input**

```
arr[] = [1, 2, 3, 4]
```

**Output**

```
20
```

**Explanation**

Subarrays:

```
[1], [2], [3], [4]
[1,2], [1,2,3], [1,2,3,4]
[2,3], [2,3,4]
[3,4]
```

Minimums:

```
1, 2, 3, 4, 1, 1, 1, 2, 2, 3
```

Sum = `20`

---

## Constraints

```
1 ≤ arr.size() ≤ 3 * 10^4
1 ≤ arr[i] ≤ 10^3
```

---

## Approach

Use a **Monotonic Stack** to determine how many subarrays consider `arr[i]` as the minimum.

For every element we compute:

* **Previous Smaller Element (PSE)**
* **Next Smaller Element (NSE)**

Each element contributes:

```
arr[i] * left * right
```

Where:

* `left` = number of elements to the left where `arr[i]` is minimum
* `right` = number of elements to the right where `arr[i]` is minimum

**Time Complexity:** `O(N)`
**Space Complexity:** `O(N)`

---

## C++ Solution

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++)
            ans += (long long)arr[i] * left[i] * right[i];

        return ans;
    }
};
```

---

## Java Solution

```java
class Solution {
    public int sumSubMins(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Stack<Integer> st = new Stack<>();

        for(int i = 0; i < n; i++){
            while(!st.isEmpty() && arr[st.peek()] > arr[i])
                st.pop();

            left[i] = st.isEmpty() ? i + 1 : i - st.peek();
            st.push(i);
        }

        st.clear();

        for(int i = n - 1; i >= 0; i--){
            while(!st.isEmpty() && arr[st.peek()] >= arr[i])
                st.pop();

            right[i] = st.isEmpty() ? n - i : st.peek() - i;
            st.push(i);
        }

        long ans = 0;

        for(int i = 0; i < n; i++)
            ans += (long)arr[i] * left[i] * right[i];

        return (int)ans;
    }
}
```

---

## Python Solution

```python
class Solution:
    def sumSubMins(self, arr):
        n = len(arr)
        left = [0]*n
        right = [0]*n
        stack = []

        for i in range(n):
            while stack and arr[stack[-1]] > arr[i]:
                stack.pop()

            left[i] = i+1 if not stack else i-stack[-1]
            stack.append(i)

        stack.clear()

        for i in range(n-1, -1, -1):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()

            right[i] = n-i if not stack else stack[-1]-i
            stack.append(i)

        ans = 0
        for i in range(n):
            ans += arr[i] * left[i] * right[i]

        return ans
```
