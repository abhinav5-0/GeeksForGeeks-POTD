# Count of Distinct Substrings

## Problem Statement

Given a string `s` consisting of lowercase English characters, determine the total number of **distinct non-empty substrings** present in the string.

A substring is defined as a contiguous block of characters within the string.
Two substrings are considered distinct if their contents differ, even if taken from different positions.

**Note:** Empty substring is not counted.

---

## Examples

### Example 1

**Input:** `s = "ababa"`

**Output:** `9`

**Explanation:**
Distinct substrings are:

```
a, b, ab, ba, aba, bab, abab, baba, ababa
```

### Example 2

**Input:** `s = "aaa"`

**Output:** `3`

**Explanation:**
Distinct substrings are:

```
a, aa, aaa
```

---

## Constraints

* `1 ≤ s.size() ≤ 3000`
* Characters are lowercase English letters.

---

# ✅ Optimal Solution Using Suffix Automaton (SAM)

The most efficient method to count distinct substrings in linear time is using a **Suffix Automaton**.

For each state in the automaton, the number of new distinct substrings it contributes is:

```
len[state] - len[link[state]]
```

Summing this over all states gives the total number of distinct substrings.

---

# ✔️ C++ Implementation

```cpp
class Solution {
public:
    struct State {
        int len, link;
        int next[26];
        State() : len(0), link(-1) {
            memset(next, -1, sizeof(next));
        }
    };

    vector<State> st;
    int last;

    void sa_init() {
        st.clear();
        st.push_back(State());
        last = 0;
    }

    void sa_extend(char c) {
        int cur = st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        int p = last;
        int letter = c - 'a';

        while (p != -1 && st[p].next[letter] == -1) {
            st[p].next[letter] = cur;
            p = st[p].link;
        }

        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[letter];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;

                while (p != -1 && st[p].next[letter] == q) {
                    st[p].next[letter] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    int countSubs(string& s) {
        sa_init();
        for (char c : s) sa_extend(c);

        long long ans = 0;
        for (int i = 1; i < (int)st.size(); i++) {
            ans += st[i].len - st[st[i].link].len;
        }
        return ans;
    }
};
```

---

## ✔️ Time Complexity

* Building SAM: **O(n)**
* Counting substrings: **O(n)**

Total: **O(n)** (fast enough for n = 3000).

---

If you'd like, I can also add:

* A suffix array + LCP alternative solution
* A visual explanation of Suffix Automaton
* A walkthrough for the examples

Just tell me!
