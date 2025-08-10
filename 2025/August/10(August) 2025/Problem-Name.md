# Palindrome SubStrings

**Difficulty:** Hard
**Accuracy:** 45.8%
**Submissions:** 52K+
**Points:** 8
**Average Time:** 30m

---

## Problem Statement

Given a string `s`, count all palindromic substrings present in the string. The length of the palindromic substring must be **greater than or equal to 2**.

A substring is palindromic if it reads the same forwards and backwards.

### Examples

**Input:**

```
s = "abaab"
```

**Output:**

```
3
```

**Explanation:**
All palindromic substrings (of length > 1) are: `"aba"`, `"aa"`, `"baab"`.

**Input:**

```
s = "aaa"
```

**Output:**

```
3
```

**Explanation:**
All palindromic substrings (of length > 1) are: `"aa"`, `"aa"`, `"aaa"`.

**Input:**

```
s = "abbaeae"
```

**Output:**

```
4
```

**Explanation:**
All palindromic substrings (of length > 1) are: `"bb"`, `"abba"`, `"aea"`, `"eae"`.

### Constraints

* 2 ≤ `s.size()` ≤ 5 × 10^3
* `s` contains only lowercase English characters

---

## Approach

We can solve this problem using the **expand around center** technique, which works in **O(n²)** time and **O(1)** space.

### Steps:

1. Every palindrome has a center:

   * Odd length: center is a single character.
   * Even length: center is between two characters.
2. For each center, expand outward as long as characters match.
3. Count only palindromes of **length ≥ 2**.

---

## C++ Solution

```cpp
class Solution {
public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        // Lambda function to expand around center and count palindromes
        auto expand = [&](int left, int right) {
            int cnt = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) cnt++; // length >= 2
                left--;
                right++;
            }
            return cnt;
        };

        // Try all possible centers
        for (int i = 0; i < n; i++) {
            count += expand(i, i);     // Odd length center
            count += expand(i, i + 1); // Even length center
        }

        return count;
    }
};
```

---

## Complexity Analysis

* **Time Complexity:** O(n²) — Each center expansion takes O(n) and there are O(n) centers.
* **Space Complexity:** O(1) — Constant extra space.

---

## Example Walkthrough

For `s = "abaab"`:

* Odd center at index 1 → `"aba"`
* Even center at index 2 → `"aa"`
* Odd center at index 3 → `"baab"`

**Total Count = 3**
