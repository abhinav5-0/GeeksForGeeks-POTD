# Largest Number in One Swap

## Problem Statement

Given a string `s`, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in `s`.

### Examples

**Input:**

```
s = "768"
```

**Output:**

```
"867"
```

**Explanation:** Swapping the 1st and 3rd characters (7 and 8 respectively) gives the lexicographically largest string.

---

**Input:**

```
s = "333"
```

**Output:**

```
"333"
```

**Explanation:** Performing any swaps gives the same result i.e., "333".

### Constraints

* 1 ≤ |s| ≤ 10^5
* '0' ≤ s\[i] ≤ '9'

---

## Approach

1. Traverse the string from left to right.
2. For each character, check if there exists a larger digit later in the string to maximize the string after swapping.
3. Precompute the index of the **rightmost maximum digit** for each position using a right-to-left pass.
4. From left to right, if a digit is smaller than its rightmost maximum, swap them and return the result.
5. If no beneficial swap exists, return the original string.

---

## Example Walkthrough

### Example 1: `s = "768"`

* Rightmost max array = `[8, 8, 8]`
* At index 0 (`7`), rightmost max is `8` → swap → `"867"`

### Example 2: `s = "333"`

* Rightmost max array = `[3, 3, 3]`
* No swap possible → `"333"`

---

## C++ Implementation

```cpp
class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> rightMaxIdx(n);
        
        // last element is its own max
        rightMaxIdx[n-1] = n-1;
        
        // Fill rightMaxIdx array
        for (int i = n-2; i >= 0; i--) {
            if (s[i] > s[rightMaxIdx[i+1]]) {
                rightMaxIdx[i] = i;
            } else {
                rightMaxIdx[i] = rightMaxIdx[i+1];
            }
        }
        
        // Find first place where swap is beneficial
        for (int i = 0; i < n; i++) {
            if (s[i] < s[rightMaxIdx[i]]) {
                swap(s[i], s[rightMaxIdx[i]]);
                break; // only one swap allowed
            }
        }
        
        return s;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(n)
* **Space Complexity:** O(n)
