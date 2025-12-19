# Bus Conductor – Minimum Moves

## 🚌 Problem Statement

You are the conductor of a bus. You are given two arrays:

* `chairs[]`: positions of chairs
* `passengers[]`: positions of passengers

Both arrays have equal length `n`.

### Allowed Move

You may move a passenger left or right by **1 unit per move**.

### Goal

Return the **minimum number of moves** required so that:

* Each passenger gets **exactly one unique chair**
* Multiple chairs **can be at the same position**

---

## 🔑 Key Insight

To minimize total moves, always assign **closest chairs to closest passengers**.

This can be achieved by:

1. Sorting both arrays
2. Pairing the *i-th passenger* with the *i-th chair*
3. Summing absolute differences

This greedy strategy guarantees the minimum total distance.

---

## 🧠 Algorithm

1. Sort `chairs[]`
2. Sort `passengers[]`
3. Initialize `moves = 0`
4. For each index `i`:

   * Add `abs(chairs[i] - passengers[i])` to `moves`
5. Return `moves`

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(n log n)`
* **Space Complexity:** `O(1)` (ignoring sorting space)

---

## ✅ C++ Implementation

```cpp
class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());

        long long moves = 0;
        for (int i = 0; i < chairs.size(); i++) {
            moves += abs(chairs[i] - passengers[i]);
        }
        return moves;
    }
};
```

---

## 🧪 Example 1

**Input**

```
chairs = [3, 1, 5]
passengers = [2, 7, 4]
```

**After Sorting**

```
chairs     = [1, 3, 5]
passengers = [2, 4, 7]
```

**Moves**

```
|1 - 2| = 1
|3 - 4| = 1
|5 - 7| = 2
Total = 4
```

---

## 🧪 Example 2

**Input**

```
chairs = [2, 2, 6, 6]
passengers = [1, 3, 2, 6]
```

**After Sorting**

```
chairs     = [2, 2, 6, 6]
passengers = [1, 2, 3, 6]
```

**Moves**

```
|2 - 1| = 1
|2 - 2| = 0
|6 - 3| = 3
|6 - 6| = 0
Total = 4
```

---

## 🎯 Conclusion

Sorting both arrays and pairing them greedily gives the **minimum total moves**.
This approach is efficient, simple, and works within the g
