### Problem: ASCII Range Sum

**Difficulty:** Medium  
**Accuracy:** 52.59%  
**Submissions:** 11K+  
**Points:** 4

---

### Problem Statement:
Given a string `s` consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence. Return all such non-zero sums (order does not matter).

---

### Examples:

#### Example 1:
**Input:** `s = "abacab"`

**Output:** `[293, 294]`

**Explanation:**
- Character 'a' occurs at indices 0 and 4. Characters between: 'b', 'a', 'c' → 98 + 97 + 99 = **294**
- Character 'b' occurs at indices 1 and 5. Characters between: 'a', 'c', 'a' → 97 + 99 + 97 = **293**

#### Example 2:
**Input:** `s = "acdac"`

**Output:** `[197, 199]`

**Explanation:**
- Character 'a' occurs at indices 0 and 3. Characters between: 'c', 'd' → 99 + 100 = **199**
- Character 'c' occurs at indices 1 and 4. Characters between: 'd', 'a' → 100 + 97 = **197**

---

### Constraints:
- 1 ≤ s.size() ≤ 10^5

---

### C++ Solution:
```cpp
class Solution {
public:
    vector<int> asciirange(string& s) {
        unordered_map<char, pair<int, int>> pos; // char -> {first, last}
        int n = s.size();

        // Step 1: Record first and last positions
        for (int i = 0; i < n; ++i) {
            if (pos.find(s[i]) == pos.end())
                pos[s[i]] = {i, i};
            else
                pos[s[i]].second = i;
        }

        vector<int> result;

        // Step 2: For each character with first != last, calculate sum
        for (auto& [ch, indices] : pos) {
            int start = indices.first;
            int end = indices.second;

            if (end - start > 1) { // there are characters in between
                int sum = 0;
                for (int i = start + 1; i < end; ++i) {
                    sum += int(s[i]);
                }
                if (sum > 0)
                    result.push_back(sum);
            }
        }

        return result;
    }
};
```

---

### Notes:
- The ASCII value of a character `c` can be obtained using `int(c)`.
- Time Complexity: O(n), where n = length of the string.
- Space Complexity: O(1) since the number of lowercase letters is constant (26).
