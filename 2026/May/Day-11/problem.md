````md
# Palindrome Pairs

**Difficulty:** Hard  
**Accuracy:** 31.71%  
**Submissions:** 30K+  
**Points:** 8  

---

## Problem Statement

Given an array `arr[]` consisting of `n` strings. Determine whether there exists a pair of indices `(i, j)` such that `i ≠ j` and the concatenation `arr[i] + arr[j]` forms a palindrome.

Return **true** if such a pair exists; otherwise, return **false**.

> **Note:** A string is considered a palindrome if it reads the same forward and backward.

---

## Examples

### Example 1

**Input:**
```cpp
arr[] = {"geekf", "geeks", "or", "keeg", "abc", "bc"}
````

**Output:**

```cpp
true
```

**Explanation:**
There is a pair `"geekf"` and `"keeg"`.
Their concatenation `"geekfkeeg"` is a palindrome.

---

### Example 2

**Input:**

```cpp
arr[] = {"abc", "xyxcba", "geekst", "or", "bc"}
```

**Output:**

```cpp
true
```

**Explanation:**
There is a pair `"abc"` and `"xyxcba"`.
Their concatenation `"abcxyxcba"` is a palindrome.

---

### Example 3

**Input:**

```cpp
arr[] = {"aa"}
```

**Output:**

```cpp
false
```

**Explanation:**
There is only one string present, so the output is false.

---

## Constraints

```cpp
1 ≤ n ≤ 2 * 10^4
1 ≤ |arr[i]| ≤ 10
```

---

# C++ Solution

```cpp
class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    bool palindromePair(vector<string>& arr) {

        int n = arr.size();

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(i == j)
                    continue;

                string temp = arr[i] + arr[j];

                if(isPalindrome(temp))
                    return true;
            }
        }

        return false;
    }
};
```

---

# Time Complexity

```cpp
O(n^2 * k)
```

Where:

* `n` = number of strings
* `k` = maximum length of concatenated string

---

# Space Complexity

```cpp
O(1)
```
