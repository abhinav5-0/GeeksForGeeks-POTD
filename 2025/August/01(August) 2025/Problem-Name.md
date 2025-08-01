## Problem: Balancing Consonants and Vowels Ratio

You are given an array of strings `arr[]`, where each `arr[i]` consists of lowercase English alphabets. 
You need to find the number of balanced strings in `arr[]` which can be formed by concatenating one or more contiguous strings of `arr[]`.

A balanced string contains the **equal number of vowels and consonants**.

---

### Constraints:
- 1 ≤ arr.size() ≤ 10^5
- 1 ≤ arr[i].size() ≤ 10^5
- Total number of characters across all strings is < 10^5

---

### Example 1:
**Input:** arr = ["aeio", "aa", "bc", "ot", "cdbd"]
**Output:** 4
**Explanation:**
Balanced substrings: arr[0..4], arr[1..2], arr[1..3], arr[3..3]

### Example 2:
**Input:** arr = ["ab", "be"]
**Output:** 3
**Explanation:**
Balanced substrings: arr[0..0], arr[0..1], arr[1..1]

### Example 3:
**Input:** arr = ["tz", "gfg", "ae"]
**Output:** 0

---

### ✅ Optimized C++ Solution
```cpp
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        int res = 0, sum = 0;
        unordered_map<int, int> mp{{0, 1}}; // base case: balance 0 seen once

        for (string& s : arr) {
            int score = 0;
            for (char c : s)
                score += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : -1;

            sum += score;
            res += mp[sum];
            mp[sum]++;
        }
        return res;
    }
};
```

---

### 🧠 Intuition:
- Use a prefix sum approach where:
  - Vowel = +1
  - Consonant = -1
- Store counts of each prefix balance in a map.
- Every time the same balance appears again, it means a balanced segment exists between the two indices.

---

### 🕒 Time & Space Complexity:
- **Time Complexity:** O(N), where N = total characters across all strings
- **Space Complexity:** O(N), for storing prefix balances
