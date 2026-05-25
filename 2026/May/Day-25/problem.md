# Elements in the Range

## Problem Statement

Given an array `arr[]` containing **distinct positive integers**, and two integers `start` and `end` defining a range, determine whether the array contains **all elements** within the inclusive range `[start, end]`.

Return:

- `true` → if all elements in the range exist in the array
- `false` → otherwise

---

## Examples

### Example 1

**Input:**

```text
start = 2
end = 5
arr[] = [1, 4, 5, 2, 7, 8, 3]
```

**Output:**

```text
true
```

**Explanation:**

The range `[2, 5]` contains:

```text
2, 3, 4, 5
```

All of these elements are present in the array.

---

### Example 2

**Input:**

```text
start = 2
end = 6
arr[] = [1, 4, 5, 2, 7, 8, 3]
```

**Output:**

```text
false
```

**Explanation:**

The element `6` is missing from the array, so all elements in the range are not present.

---

## Constraints

```text
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^5
0 ≤ start ≤ end ≤ 10^5
```

---

# Approach

To efficiently check whether all numbers in the range exist:

1. Store all array elements in a `set`
2. Traverse from `start` to `end`
3. If any element is missing from the set, return `false`
4. Otherwise return `true`

---

# Time Complexity

```text
O(n + (end - start + 1))
```

- `O(n)` for inserting elements into the set
- `O(range)` for checking all numbers in the range

---

# Space Complexity

```text
O(n)
```

Used for storing elements in the set.

---

# C++ Solution

```cpp
class Solution {
  public:
  
    bool checkElements(int start, int end, vector<int> &arr) {
        
        unordered_set<int> s(arr.begin(), arr.end());

        for (int i = start; i <= end; i++) {
            if (s.find(i) == s.end()) {
                return false;
            }
        }

        return true;
    }
};
```

---

# Dry Run

## Input

```text
start = 2
end = 5
arr[] = [1, 4, 5, 2, 7, 8, 3]
```

## Step 1: Store elements in set

```text
{1, 2, 3, 4, 5, 7, 8}
```

## Step 2: Check range elements

| Element | Present? |
|----------|-----------|
| 2 | Yes |
| 3 | Yes |
| 4 | Yes |
| 5 | Yes |

All elements are present.

## Final Answer

```text
true
```
