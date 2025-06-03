# Problem: Substrings with K Distinct Characters

## Difficulty

Medium

## Accuracy

20.46%

## Submissions

160K+

## Points

4

## Average Time

20 minutes

---

## Problem Statement

Given a string consisting of lowercase characters and an integer `k`, the task is to count all possible substrings (not necessarily distinct) that have **exactly** `k` distinct characters.

---

## Examples

### Example 1

**Input:**

```txt
s = "abc", k = 2
```

**Output:**

```txt
2
```

**Explanation:**
Possible substrings are \["ab", "bc"]

### Example 2

**Input:**

```txt
s = "aba", k = 2
```

**Output:**

```txt
3
```

**Explanation:**
Possible substrings are \["ab", "ba", "aba"]

### Example 3

**Input:**

```txt
s = "aa", k = 1
```

**Output:**

```txt
3
```

**Explanation:**
Possible substrings are \["a", "a", "aa"]

---

## Constraints

* \$1 \leq |s| \leq 10^6\$
* \$1 \leq k \leq 26\$

---

## Approach

We use the sliding window technique with a helper function that counts substrings with **at most k** distinct characters.

### Formula:

```text
Substrings with exactly k distinct characters = atMostK(k) - atMostK(k - 1)
```

---

## Code (C++)

```cpp
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countSubstr(string& s, int k) {
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }

private:
    int atMostKDistinct(const string& s, int k) {
        if (k == 0) return 0;

        unordered_map<char, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                ++left;
            }

            count += (right - left + 1);  // Count all substrings ending at right
        }

        return count;
    }
};
```

---

## Time Complexity

* **O(n)** where `n` is the length of the string.

## Space Complexity

* **O(1)** since the number of lowercase letters is bounded (at most 26).

---

## Tags

`sliding-window`, `hashmap`, `string`, `two-pointers`
