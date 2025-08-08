## Longest Prefix Suffix

**Difficulty:** Hard
**Accuracy:** 27.91%
**Points:** 8

---

### Problem Statement

Given a string `s` of lowercase English alphabets, find the length of the **longest proper prefix** which is also a suffix.

**Note:**

* Prefix and suffix can be overlapping.
* They should **not** be equal to the entire string.

---

### Examples

**Input:**

```
s = "abab"
```

**Output:**

```
2
```

**Explanation:** The string `"ab"` is the longest prefix and suffix.

**Input:**

```
s = "aabcdaabc"
```

**Output:**

```
4
```

**Explanation:** The string `"aabc"` is the longest prefix and suffix.

**Input:**

```
s = "aaaa"
```

**Output:**

```
3
```

**Explanation:** `"aaa"` is the longest prefix and suffix.

---

### Constraints

* `1 ≤ s.size() ≤ 10^6`
* `s` contains only lowercase English alphabets.

---

### Approach

We can solve this using the **LPS (Longest Prefix Suffix)** computation from the **KMP algorithm**:

* Create an array `lps` where `lps[i]` stores the length of the longest proper prefix of `s[0..i]` which is also a suffix.
* The last value `lps[n-1]` gives the answer.

**Steps:**

1. Initialize `lps` array with 0s.
2. Use two pointers:

   * `len` → length of the current longest prefix-suffix match.
   * `i` → iterate over the string.
3. If characters match, increase both `len` and `i`, update `lps[i]`.
4. If mismatch:

   * If `len > 0`, set `len = lps[len-1]`.
   * Else, set `lps[i] = 0` and increment `i`.
5. Return `lps[n-1]`.

---

### Time Complexity

* **O(n)** — each character is processed at most twice.

### Space Complexity

* **O(n)** for the `lps` array.

---

### Code Implementation (C++)

```cpp
class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.size();
        vector<int> lps(n, 0);
        
        int len = 0; // length of current matching prefix-suffix
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps[n - 1];
    }
};
```
