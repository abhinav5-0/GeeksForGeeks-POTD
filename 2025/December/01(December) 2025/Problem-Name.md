# XOR Pairs Less Than K

## Problem

Given an array `arr[]` and an integer `k`, count the number of pairs `(i, j)` such that:

* `i < j`
* `(arr[i] XOR arr[j]) < k`

### Examples

**Input:** `arr = [1, 2, 3, 5], k = 5`
**Output:** `4`

**Input:** `arr = [3, 5, 6, 8], k = 7`
**Output:** `3`

### Constraints

* `1 ≤ arr.size(), k ≤ 5*10^4`
* `1 ≤ arr[i] ≤ 5*10^4`

---

## Efficient Approach — Binary Trie

Brute force O(n²) is too slow for n = 5×10⁴.
We use a **binary trie** (0/1 trie) to efficiently count how many previous numbers `x` satisfy:

```
(x XOR num) < k
```

This is checked bit‑by‑bit using the binary trie.

### Key Idea

Let:

* `bi` = ith bit of current number
* `ki` = ith bit of k

While traversing:

* If `ki == 1` → You can add counts from the branch `(bi)` because choosing that would keep XOR's prefix less than k.
* Then you must move to branch `(1 ^ bi)` to continue comparison.
* If `ki == 0` → You must match bits exactly: only move to `(bi)` branch.

This gives **O(16 * n)** complexity (since max value < 2¹⁶).

---

## Code (C++)

```cpp
class Solution {
public:
    struct Trie {
        Trie* child[2];
        int cnt;
        Trie() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    void insert(Trie* root, int num) {
        for (int i = 15; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (!root->child[b]) root->child[b] = new Trie();
            root = root->child[b];
            root->cnt++;
        }
    }

    int query(Trie* root, int num, int k) {
        int ans = 0;
        for (int i = 15; i >= 0; i--) {
            if (!root) break;
            int b = (num >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == 1) {
                // Add counts from same-bit branch
                if (root->child[b]) ans += root->child[b]->cnt;
                // Move to opposite branch
                root = root->child[b ^ 1];
            } else {
                // Must match exactly
                root = root->child[b];
            }
        }
        return ans;
    }

    int cntPairs(vector<int>& arr, int k) {
        Trie* root = new Trie();
        int count = 0;

        for (int num : arr) {
            count += query(root, num, k);
            insert(root, num);
        }
        return count;
    }
};
```

---

## Time Complexity

* Insert: `O(log M)` where `M = 5×10⁴` → 16 bits
* Query: `O(log M)`
* Total: **O(n log M)**

Fits easily within constraints.

---

## Summary

✔ Efficient binary‑trie solution
✔ Counts pairs with XOR < k
✔ Works in O(n log M)

This is the optimal solution.
