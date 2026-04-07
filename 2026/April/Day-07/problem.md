# Stable Marriage Problem

## 🧩 Problem Statement

You are given two arrays `men[][]` and `women[][]`, each of length `n`, where:

* `men[i]` represents the preference list of the **i-th man**, ranking all women in order of preference.
* `women[i]` represents the preference list of the **i-th woman**, ranking all men in order of preference.

## 🎯 Objective

Form `n` pairs (marriages) such that:

* Each man is matched with exactly one woman.
* Each woman is matched with exactly one man.
* The matching is **stable**.

### 💡 Stability Condition

A matching is stable if **there is no pair (man, woman)** such that:

* Both prefer each other over their current partners.

It is guaranteed that a stable matching always exists.

Return the stable matching **from the men's perspective**, meaning:

* Men propose to women.

## 📤 Output Format

Return an array `result[]` of size `n`, where:

* `result[i]` = index of the woman matched with the `i-th man`.

---

## 🧪 Examples

### Example 1

**Input:**

```
n = 2
men = [[0, 1], [0, 1]]
women = [[0, 1], [0, 1]]
```

**Output:**

```
[0, 1]
```

**Explanation:**

* Man 0 → Woman 0 (both first choice)
* Man 1 → Woman 1 (both second choice)

---

### Example 2

**Input:**

```
n = 3
men = [[0,1,2], [0,1,2], [0,1,2]]
women = [[2,1,0], [2,1,0], [2,1,0]]
```

**Output:**

```
[2, 1, 0]
```

**Explanation:**

* Man 0 → Woman 2
* Man 1 → Woman 1
* Man 2 → Woman 0

---

## ⚙️ Constraints

* `2 ≤ n ≤ 10^3`
* `0 ≤ men[i][j] < n`
* `0 ≤ women[i][j] < n`

---

## 🚀 Approach (Gale-Shapley Algorithm)

1. All men are initially free.
2. Each free man proposes to the highest-ranked woman he hasn't proposed to yet.
3. Each woman:

   * Accepts the proposal if she is free.
   * If engaged, she chooses between current partner and new proposer based on preference.
4. Repeat until all are matched.

---

## ⏱️ Complexity

* **Time Complexity:** `O(n^2)`
* **Space Complexity:** `O(n^2)`

---

## 💻 C++ Implementation

```cpp
class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>>& men, vector<vector<int>>& women) {
        int n = men.size();

        vector<int> womanPartner(n, -1);
        vector<int> manNext(n, 0);
        vector<bool> freeMan(n, true);

        vector<vector<int>> rank(n, vector<int>(n));

        // Precompute rankings of men for each woman
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        int freeCount = n;

        while (freeCount > 0) {
            int m;
            for (m = 0; m < n; m++) {
                if (freeMan[m]) break;
            }

            int w = men[m][manNext[m]++];

            if (womanPartner[w] == -1) {
                womanPartner[w] = m;
                freeMan[m] = false;
                freeCount--;
            } else {
                int m1 = womanPartner[w];

                if (rank[w][m] < rank[w][m1]) {
                    womanPartner[w] = m;
                    freeMan[m] = false;
                    freeMan[m1] = true;
                }
            }
        }

        vector<int> result(n);
        for (int w = 0; w < n; w++) {
            result[womanPartner[w]] = w;
        }

        return result;
    }
};
```

---

## ☕ Java Implementation

```java
class Solution {
    public int[] stableMarriage(int[][] men, int[][] women) {
        int n = men.length;

        int[] womanPartner = new int[n];
        int[] manNext = new int[n];
        boolean[] freeMan = new boolean[n];

        Arrays.fill(womanPartner, -1);
        Arrays.fill(freeMan, true);

        int[][] rank = new int[n][n];

        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        int freeCount = n;

        while (freeCount > 0) {
            int m = 0;
            while (!freeMan[m]) m++;

            int w = men[m][manNext[m]++];

            if (womanPartner[w] == -1) {
                womanPartner[w] = m;
                freeMan[m] = false;
                freeCount--;
            } else {
                int m1 = womanPartner[w];

                if (rank[w][m] < rank[w][m1]) {
                    womanPartner[w] = m;
                    freeMan[m] = false;
                    freeMan[m1] = true;
                }
            }
        }

        int[] result = new int[n];
        for (int w = 0; w < n; w++) {
            result[womanPartner[w]] = w;
        }

        return result;
    }
}
```

---

## 🐍 Python Implementation

```python
class Solution:
    def stableMarriage(self, men, women):
        n = len(men)

        woman_partner = [-1] * n
        man_next = [0] * n
        free_man = [True] * n

        rank = [[0] * n for _ in range(n)]

        for w in range(n):
            for i in range(n):
                rank[w][women[w][i]] = i

        free_count = n

        while free_count > 0:
            m = next(i for i in range(n) if free_man[i])

            w = men[m][man_next[m]]
            man_next[m] += 1

            if woman_partner[w] == -1:
                woman_partner[w] = m
                free_man[m] = False
                free_count -= 1
            else:
                m1 = woman_partner[w]

                if rank[w][m] < rank[w][m1]:
                    woman_partner[w] = m
                    free_man[m] = False
                    free_man[m1] = True

        result = [0] * n
        for w in range(n):
            result[woman_partner[w]] = w

        return result
```

---

## 📝 Summary

* Classic matching problem solved using **Gale-Shapley Algorithm**.
* Guarantees a **stable and optimal (for men)** matching.
* Widely used in real-world allocation systems (e.g., college admissions, job matching).
