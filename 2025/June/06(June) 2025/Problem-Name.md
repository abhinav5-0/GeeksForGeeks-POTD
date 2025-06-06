# Rabin-Karp Pattern Search Algorithm

## Problem Statement

Given two strings:

* A **text** string in which you want to search.
* A **pattern** string that you are looking for within the text.

Return **all positions (1-based indexing)** where the pattern occurs as a substring in the text. If the pattern does not occur, return an empty list.

All characters in both strings are lowercase English letters (a to z).

---

## Examples

### Example 1

**Input:**

```
text = "birthdayboy"
pattern = "birth"
```

**Output:**

```
[1]
```

**Explanation:** The string "birth" occurs at index 1 in the text.

### Example 2

**Input:**

```
text = "geeksforgeeks"
pattern = "geek"
```

**Output:**

```
[1, 9]
```

**Explanation:** The string "geek" occurs twice in the text.

---

## Constraints

* `1 <= text.size() <= 5 * 10^5`
* `1 <= pattern.size() <= text.size()`

---

## Approach: Rabin-Karp Algorithm

### Idea:

Use a rolling hash to efficiently compare substrings of the text to the pattern.

* Compute the hash of the pattern and the first window of the text.
* Slide the window over the text, updating the hash each time.
* When the hashes match, do a character-by-character check to confirm a match.

### Time Complexity:

* Average Case: O(n + m)
* Worst Case (with many hash collisions): O(nm)

---

## C++ Implementation

```cpp
class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        vector<int> result;
        int m = pat.size();
        int n = txt.size();

        if (m > n) return result;

        int d = 26; // Number of characters in alphabet
        int q = 101; // A prime number for modulus
        int h = 1;

        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }

        int p = 0; // Hash value for pattern
        int t = 0; // Hash value for text window

        for (int i = 0; i < m; i++) {
            p = (d * p + (pat[i] - 'a')) % q;
            t = (d * t + (txt[i] - 'a')) % q;
        }

        for (int i = 0; i <= n - m; i++) {
            if (p == t) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) result.push_back(i + 1);
            }

            if (i < n - m) {
                t = (d * (t - (txt[i] - 'a') * h) + (txt[i + m] - 'a')) % q;
                if (t < 0) t += q;
            }
        }

        return result;
    }
};
```

---

## Tags

* String Matching
* Hashing
* Rabin-Karp
* Rolling Hash
* Algorithm
