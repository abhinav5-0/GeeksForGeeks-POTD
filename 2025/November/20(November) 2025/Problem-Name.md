# Make Strings Equal — DP + Graph (Floyd–Warshall) Solution

## **Problem Summary**

You are given two strings **s** and **t**, both containing lowercase English letters. You can transform characters using a list of directed transformations:

```
[x -> y] with cost[i]
```

You may apply transformations any number of times.

Your task is to determine the **minimum cost** required to make both strings identical. If it is impossible, return **-1**.

---

## **Key Ideas**

### ✔ Small alphabet → 26 letters

Only characters 'a' to 'z' are involved, so we can run **Floyd–Warshall** to compute minimum transformation cost between all pairs.

### ✔ Convert both characters at position i to a common letter

For each index `i`, we try converting `s[i]` and `t[i]` into the **same** letter `c`.

Cost = `dist[s[i]][c] + dist[t[i]][c]`

Pick minimum over all `c`.

If no such `c` exists → return `-1`.

---

## **Algorithm Steps**

1. Initialize a 26×26 matrix `dist`, where:

   * `dist[i][i] = 0`
   * `dist[u][v] = cost` if there is a direct transformation.

2. Run **Floyd–Warshall** to compute minimum conversion cost for all `(i, j)`.

3. For each position `k` in the strings:

   * If `s[k] == t[k]`, cost = 0.
   * Otherwise try converting both into every letter `c ∈ [0..25]`.
   * Accumulate best possible cost.

4. If no common `c` works at any position → return `-1`.

---

## **Time Complexity**

* Floyd–Warshall: `26³ = 17576`
* Checking each position: `O(n × 26)`

Total complexity: **O(n × 26)** → Efficient for `n ≤ 100000`.

---

## **C++ Code Implementation**

```cpp
class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {

        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Distance to self is zero
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        // Add transformation edges
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }

        // Floyd–Warshall algorithm
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';

            if (a == b) continue;

            int best = INF;

            // Try converting both to the same letter
            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    best = min(best, dist[a][c] + dist[b][c]);
                }
            }

            if (best == INF) return -1;
            ans += best;
        }

        return ans;
    }
};
```

---

## **Example Walkthroughs**

### **Example 1**

```
s = "abcc"
t = "bccc"
transform = {a->b, b->c, c->a}
cost = {2, 1, 4}
```

Minimum cost = **3**.

### **Example 2**

```
s = "az"
t = "dc"
transform gives: a→b→c→d, z→c
```

Minimum cost = **20**.

### **Example 3**

Impossible → Output = **-1**.

---

## **Final Notes**

* Floyd–Warshall is perfect for 26-letter transformations.
* For each position, we search for the best common letter.

If you want a **flowchart**, **diagram**, or **dry run table**, tell me!
