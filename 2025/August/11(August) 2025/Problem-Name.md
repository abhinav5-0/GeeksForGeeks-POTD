# Maximum Non-Overlapping Odd Palindrome Sum

**Difficulty:** Hard
**Goal:** Given a string `s` of lowercase letters, find the maximum possible sum of lengths of any two **non-empty**, **non-overlapping**, **odd-length** palindromic substrings.

**Formal:** Choose substrings `s[i...j]` and `s[k...l]` such that `1 ≤ i ≤ j < k ≤ l ≤ s.size()`, both are palindromes of odd length, and they do not overlap. Return the maximum sum `len(s[i...j]) + len(s[k...l])`.

**Constraints:**

* `2 ≤ s.size() ≤ 10^5`

---

## Examples

**Input:** `s = "xyabacbcz"`
**Output:** `6`
**Explanation:** pick "aba" (3) and "cbc" (3).

**Input:** `s = "gfgforgeeks"`
**Output:** `4`
**Explanation:** pick "gfg" (3) and "g" (1).

---

## Observations

* Every **odd-length** palindrome is centered at a single character (a center index `c`). If we know its maximum radius/length for each center, we can reason about which palindromes can be placed left/right without overlap.
* The two palindromes must be non-overlapping; one ends strictly before the other starts.

---

## High-level approach (O(n) target)

1. Compute, for every index `i`, the maximum odd palindrome radius/length centered at `i`.
2. From those palindromes, build two helper arrays:

   * `bestLeft[i]` = maximum length of an odd palindrome whose **end** is `≤ i`.
   * `bestRight[i]` = maximum length of an odd palindrome whose **start** is `≥ i`.
3. For every split between `i` and `i+1`, combine `bestLeft[i] + bestRight[i+1]` and take the maximum.

To meet the constraint `n ≤ 10^5` efficiently, we should compute odd palindrome radii using **Manacher's algorithm** (linear time). A simpler center-expansion method is easier to implement but can be `O(n^2)` in the worst case (e.g., all characters equal) and may TLE on upper bounds.

---

## Implementation 1 — simple center expansion (clear but worst-case O(n²))

```cpp
class Solution {
public:
    int maxSum(string &s) {
        int n = s.size();
        vector<int> bestLeft(n, 0), bestRight(n, 0);

        // Expand around each center (odd palindromes)
        for (int center = 0; center < n; ++center) {
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1; // odd
                bestLeft[r] = max(bestLeft[r], len);
                bestRight[l] = max(bestRight[l], len);
                --l; ++r;
            }
        }

        // prefix max for bestLeft (largest palindrome ending at or before i)
        for (int i = 1; i < n; ++i) bestLeft[i] = max(bestLeft[i], bestLeft[i-1]);
        // suffix max for bestRight (largest palindrome starting at or after i)
        for (int i = n-2; i >= 0; --i) bestRight[i] = max(bestRight[i], bestRight[i+1]);

        int ans = 0;
        for (int i = 0; i < n-1; ++i) ans = max(ans, bestLeft[i] + bestRight[i+1]);
        return ans;
    }
};
```

> **Note:** This is straightforward and often passes smaller inputs, but for worst-case large inputs (`n = 1e5`) its expansion step can be quadratic.

---

## Implementation 2 — Manacher's algorithm (O(n))

We'll adapt Manacher to compute odd-length palindrome radii directly, then build `bestLeft` and `bestRight` similarly.

```cpp
class Solution {
public:
    int maxSum(string &s) {
        int n = s.size();
        vector<int> d1(n); // d1[i] = radius for odd palindromes centered at i
        // Manacher's odd-length pass
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            d1[i] = k; // radius in terms of characters counted from center (k), length = 2*k - 1
            if (i + k - 1 > r) { l = i - k + 1; r = i + k - 1; }
        }

        vector<int> bestLeft(n, 0), bestRight(n, 0);
        // Convert radii to lengths and update bestLeft/bestRight
        for (int center = 0; center < n; ++center) {
            int radius = d1[center];
            if (radius <= 0) continue;
            int len = 2 * radius - 1;
            int start = center - radius + 1;
            int end   = center + radius - 1;
            bestLeft[end] = max(bestLeft[end], len);
            bestRight[start] = max(bestRight[start], len);
        }

        for (int i = 1; i < n; ++i) bestLeft[i] = max(bestLeft[i], bestLeft[i-1]);
        for (int i = n-2; i >= 0; --i) bestRight[i] = max(bestRight[i], bestRight[i+1]);

        int ans = 0;
        for (int i = 0; i < n-1; ++i) ans = max(ans, bestLeft[i] + bestRight[i+1]);
        return ans;
    }
};
```

---

## Complexity

* Manacher pass: `O(n)`
* Building/propagating `bestLeft`/`bestRight`: `O(n)`
* Final scan: `O(n)`

Overall: **O(n)** time and **O(n)** extra space.

---

## Implementation notes & tips

* Always use the Manacher version for `n` up to `1e5` to avoid worst-case TLE.
* Be careful about index arithmetic when converting radii (`d1[i]`) to start/end indices: for odd palindromes with radius `k`, the length is `2*k - 1`, start = `i - k + 1`, end = `i + k - 1`.
* This problem restricts palindromes to **odd lengths only**, so we only need the `d1` array from Manacher. If even-length palindromes were allowed we'd use `d2` too.

---

If you want: I can also add a short test harness and some example runs in C++ to this document, or create a small README-style explanation for using the code in a competitive environment.
