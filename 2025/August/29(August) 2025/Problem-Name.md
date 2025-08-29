# Smallest Window Containing All Characters

**Difficulty:** Hard
**Accuracy:** 30.19%
**Submissions:** 184K+
**Points:** 8
**Average Time:** 30m

---

## Problem Statement

Given two strings `s` and `p`. Find the **smallest substring** in `s` consisting of all the characters (including duplicates) of the string `p`. Return an empty string in case no such substring is present.

If there are multiple substrings of the same length, return the one with the least starting index.

---

### Examples

**Input:**

```text
s = "timetopractice", p = "toc"
```

**Output:**

```text
"toprac"
```

**Explanation:** `toprac` is the smallest substring in which `toc` can be found.

---

**Input:**

```text
s = "zoomlazapzo", p = "oza"
```

**Output:**

```text
"apzo"
```

**Explanation:** `apzo` is the smallest substring in which `oza` can be found.

---

**Input:**

```text
s = "zoom", p = "zooe"
```

**Output:**

```text
""
```

**Explanation:** No substring is present containing all characters of `p`.

---

### Constraints

* `1 ≤ s.length(), p.length() ≤ 10^6`
* `s`, `p` consist of lowercase English letters

---

## Approach

This is a **sliding window + hashing** problem, similar to the classic *Minimum Window Substring*.

1. Count frequencies of characters in `p` (using `need` array).
2. Use a **sliding window** (`left`, `right`) to traverse `s`.
3. Expand the window with `right` and update `window` counts.
4. If window contains all required characters → try to shrink with `left` to minimize.
5. Keep track of the best (minimum length) substring.
6. Return the result, or `""` if none is found.

---

## Solution Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        vector<int> need(26, 0), window(26, 0);
        for (char c : p) need[c - 'a']++;

        int required = 0;
        for (int x : need) if (x > 0) required++;

        int formed = 0;
        int left = 0, minLen = INT_MAX, startIdx = -1;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c - 'a']++;

            if (need[c - 'a'] > 0 && window[c - 'a'] == need[c - 'a'])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char d = s[left];
                window[d - 'a']--;
                if (need[d - 'a'] > 0 && window[d - 'a'] < need[d - 'a'])
                    formed--;
                left++;
            }
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};
```

---

## Example Walkthrough

**Input:** `s = "timetopractice", p = "toc"`

* Need = {t:1, o:1, c:1}
* Expand until window `"timetopra"` → contains all.
* Shrink to `"toprac"` → valid & smallest.
* **Answer = `"toprac"`**

---

✅ Efficient solution using **sliding window** with **O(n)** time complexity.
