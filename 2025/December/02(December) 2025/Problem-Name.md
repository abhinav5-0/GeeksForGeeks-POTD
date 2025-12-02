# Maximise String Score — Editorial & Optimized Solution

## ✅ Problem Summary

You are given:

* A string `s`
* A list of allowed jumps `jumps[][]`, where each entry `[s1, s2]` means you may jump from character `s1` to character `s2` in the string.
* You may **always jump to the next occurrence of the same character**.
* A jump from index `i → j` (where `j > i`) gives score:

```
score(i, j) = sum( ascii(s[k]) for i ≤ k < j AND s[k] != s[j] )
```

You start at index **0** and may make any valid sequence of jumps.
Goal → **maximize total score**.

Constraints: `|s| ≤ 2×10⁵`, so we need an O(n log n) or O(n·26) solution.

---

## ✅ Key Ideas

### 1️⃣ Self jumps

You may always jump from a character to any later occurrence of the same character.
So insert all `(c → c)` edges.

### 2️⃣ Next Occurrence Table (nxt)

For each index `i` and each character `c`, store the next position `j > i` where `c` appears.
This enables O(1) jumps.

### 3️⃣ Prefix Sum

To compute score efficiently:

```
prefix[k] = sum of ascii(s[0..k-1])
```

Score formula becomes constant-time.

### 4️⃣ DP from Right to Left

`dp[i] = max score achievable starting from index i`.

We try all allowed jumps from `s[i]` to target chars.
Each transition is O(1).

Total complexity: **O(n × 26)**.

---

## ✅ Final Optimal Code (C++)

```cpp
class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();

        // Add self-jumps
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});

        // nxt[i][c] = next index > i with character c
        vector<vector<int>> nxt(n, vector<int>(26, -1));
        vector<int> last(26, -1);

        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = last;
            last[s[i] - 'a'] = i;
        }

        // adj list: from char x → all chars it can jump to
        vector<vector<int>> ch(26);
        for (auto &j : jumps) ch[j[0] - 'a'].push_back(j[1]);

        // prefix sum of ascii values
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + s[i];

        vector<int> dp(n, 0);

        // DP from second-last index to 0
        for (int i = n - 2; i >= 0; i--) {
            for (int c : ch[s[i] - 'a']) {
                int j = nxt[i][c - 'a'];  // next index with char c
                if (j != -1) {
                    int exclude = (c == s[i]) ? 1 : 0;
                    dp[i] = max(dp[i], pre[j] - pre[i + exclude] + dp[j]);
                }
            }
        }

        return dp[0];
    }
};
```

---

## 🧠 Complexity

* Building next-occ array: **O(n×26)**
* DP transitions: **O(n×26)**
* Prefix sums: **O(n)**

Total: **O(n × 26)** → runs easily under limits.

---

## 🎯 Final Answer

This method is fast, clean, and passes all constraints.

If you'd like, I can also add:

* Dry run examples
* Diagrams explaining jumps
* Python/Java versions
* More test cases

Just ask!
