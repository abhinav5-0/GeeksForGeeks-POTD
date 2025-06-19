# Case-specific Sorting of Strings

**Difficulty:** Medium
**Accuracy:** 69.88%
**Submissions:** 66K+
**Points:** 4
**Average Time:** 45m

## Problem Statement

Given a string `s` consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the `i`th place in the original string had an uppercase character, then it should not have a lowercase character after being sorted and vice versa.

### Examples:

**Input:**

```
s = "GEekS"
```

**Output:**

```
EGekS
```

**Explanation:**
Sorted form of given string with the same case of character will result in output as EGekS.

**Input:**

```
s = "XWMSPQ"
```

**Output:**

```
MPQSWX
```

**Explanation:**
Since all characters are of the same case, we can simply perform a sorting operation on the entire string.

---

## Constraints:

* 1 ≤ s.length() ≤ 10^5

---

## Function Signature

```cpp
class Solution {
  public:
    string caseSort(string& s);
};
```

---

## Expected Approach

1. Separate the characters in the string into two arrays based on case: one for lowercase and one for uppercase.
2. Sort both arrays independently.
3. Traverse the original string and for each position:

   * If the character was originally lowercase, replace it with the next character from the sorted lowercase array.
   * If the character was originally uppercase, replace it with the next character from the sorted uppercase array.
4. Return the newly constructed string.

---

## Sample Code

```cpp
class Solution {
  public:
    string caseSort(string& s) {
        string lower, upper;

        // Separate characters by case
        for (char ch : s) {
            if (islower(ch)) lower.push_back(ch);
            else upper.push_back(ch);
        }

        // Sort both character sets
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        // Replace characters based on original case
        int li = 0, ui = 0;
        string result = s;

        for (int i = 0; i < s.length(); ++i) {
            if (islower(s[i])) {
                result[i] = lower[li++];
            } else {
                result[i] = upper[ui++];
            }
        }

        return result;
    }
};
```

---

## Notes

* This solution runs in O(n log n) time due to sorting, where n is the length of the string.
* Space complexity is O(n) for storing the lowercase and uppercase arrays separately.
* It preserves the case-position mapping of the original string while ensuring that characters are sorted within their case groups.
