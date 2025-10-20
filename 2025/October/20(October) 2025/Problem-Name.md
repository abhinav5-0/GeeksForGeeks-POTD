## Number of BST From Array

**Difficulty:** Hard
**Accuracy:** 78.62%
**Points:** 8

### 🧩 Problem Statement

You are given an integer array `arr[]` containing **distinct elements**.

Your task is to return an array where the `i`th element denotes the **number of unique BSTs** formed when `arr[i]` is chosen as the root.

---

### 🧠 Example

**Input:**
`arr[] = [2, 1, 3]`

**Output:**
`[1, 2, 2]`

**Explanation:**

* When root = 1 → Left(0 nodes), Right(2 nodes) → Catalan(0) × Catalan(2) = 1 × 2 = 2
* When root = 2 → Left(1 node), Right(1 node) → Catalan(1) × Catalan(1) = 1 × 1 = 1
* When root = 3 → Left(2 nodes), Right(0 nodes) → Catalan(2) × Catalan(0) = 2 × 1 = 2
  → `[1, 2, 2]`

---

### ⚙️ Constraints

* 1 ≤ arr.size() ≤ 6
* 1 ≤ arr[i] ≤ 15

---

### 💡 Approach

1. Sort the array to maintain BST order.
2. Precompute **Catalan numbers** up to `n ≤ 6` using dynamic programming:

   * `C0 = 1`
   * `Cn = Σ (Ci × Cn−i−1)` for i = 0 to n−1
3. For each element in sorted array:

   * `left = number of elements smaller`
   * `right = number of elements greater`
   * `count = Catalan[left] × Catalan[right]`
4. Map the results back to original order and return.

---

### 📘 Catalan Number Formula

[ C_n = \frac{(2n)!}{(n+1)! \times n!} ]

Or recursively defined as:
`C0 = 1,  Cn = Σ(Ci × Cn−i−1)`

---

### 🧑‍💻 C++ Implementation

```cpp
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> catalan(n + 1, 0);
        catalan[0] = catalan[1] = 1;

        // Compute Catalan numbers
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }

        // Sort array to maintain BST order
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, int> bstCount;

        for (int i = 0; i < n; i++) {
            int left = i;             // elements smaller
            int right = n - i - 1;    // elements greater
            bstCount[sorted[i]] = catalan[left] * catalan[right];
        }

        // Map back to original order
        vector<int> result;
        for (int val : arr) {
            result.push_back(bstCount[val]);
        }

        return result;
    }
};
```

---

### ✅ Example Run

**Input:**
`arr = [2, 1, 3]`

**Output:**
`[1, 2, 2]`

**Input:**
`arr = [2, 1]`

**Output:**
`[1, 1]`

---

### 📊 Time Complexity

* **O(n²)** for Catalan computation (small n ≤ 6)
* **O(n log n)** for sorting
* **Overall:** `O(n²)`

---

### 🧩 Key Insight

Each BST configuration depends only on how many nodes go to the left and right — not on actual values. Hence, **Catalan numbers** perfectly model this distribution.
