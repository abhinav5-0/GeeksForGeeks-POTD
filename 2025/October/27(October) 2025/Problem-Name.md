## Find K Smallest Sum Pairs

**Difficulty:** Medium
**Accuracy:** 62.51%
**Points:** 4

---

### 🧩 Problem Statement

Given two integer arrays `arr1[]` and `arr2[]` sorted in ascending order and an integer `k`, your task is to find `k` pairs with the smallest sums, such that one element of each pair belongs to `arr1[]` and the other belongs to `arr2[]`.

Return the list of these `k` pairs, where each pair is represented as `[arr1[i], arr2[j]]`.

**Note:** You can return any possible `k` pairs with the smallest sums; the driver code will print `true` if it is correct.

---

### 🧠 Example 1

**Input:**
`arr1 = [1, 7, 11]`
`arr2 = [2, 4, 6]`
`k = 3`

**Output:**
`true`

**Explanation:**
All possible combinations:
`[1,2], [1,4], [1,6], [7,2], [7,4], [7,6], [11,2], [11,4], [11,6]`
Among these, the three pairs with the minimum sums are `[1,2], [1,4], [1,6]`.

---

### 🧠 Example 2

**Input:**
`arr1 = [1, 3]`
`arr2 = [2, 4]`
`k = 2`

**Output:**
`true`

**Explanation:**
All possible combinations are `[1,2], [1,4], [3,2], [3,4]`.
The two pairs with the minimum sums are `[1,2], [3,2]`.

---

### 🔒 Constraints

* `1 ≤ arr1.size(), arr2.size() ≤ 5 * 10^4`
* `1 ≤ arr1[i], arr2[j] ≤ 10^9`
* `1 ≤ k ≤ 10^3`

---

### 💡 Approach (Using Min-Heap)

We take advantage of the sorted nature of the arrays. The smallest possible sum starts from the smallest elements of both arrays.

#### Steps:

1. Use a **min-heap** (priority queue) to store tuples `(sum, i, j)` where:

   * `sum = arr1[i] + arr2[j]`
   * `i` and `j` are indices from `arr1` and `arr2`
2. Initially push the first `k` pairs `(arr1[i] + arr2[0], i, 0)` into the heap.
3. Pop the smallest pair `(sum, i, j)` from the heap and add `[arr1[i], arr2[j]]` to the result.
4. Push the next pair `(arr1[i], arr2[j+1])` for the same `i`.
5. Repeat until `k` pairs are found.

#### Time Complexity:

`O(k * log n)` where `n = min(k, arr1.size())`

#### Space Complexity:

`O(n)` for the heap.

---

### 🧮 Example Walkthrough

**Input:**
`arr1 = [1, 7, 11]`, `arr2 = [2, 4, 6]`, `k = 3`

**Heap Operations:**

```
Push: (3,0,0), (9,1,0), (13,2,0)
Pop (3,[1,2]) → Push (5,0,1)
Pop (5,[1,4]) → Push (7,0,2)
Pop (7,[1,6]) → Done (k=0)
```

**Result:**
`[[1,2], [1,4], [1,6]]`

---

### 💻 Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> result;
        int n = arr1.size(), m = arr2.size();
        
        // Min-heap: stores {sum, index1, index2}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Push the first element of each arr1 with arr2[0]
        for (int i = 0; i < n && i < k; i++) {
            minHeap.push({arr1[i] + arr2[0], i, 0});
        }
        
        // Extract k pairs with smallest sum
        while (k-- > 0 && !minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            
            int i = curr[1], j = curr[2];
            result.push_back({arr1[i], arr2[j]});
            
            // Push next pair in the same row (arr1[i], arr2[j+1])
            if (j + 1 < m) {
                minHeap.push({arr1[i] + arr2[j + 1], i, j + 1});
            }
        }
        
        return result;
    }
};
```

---

### 🏁 Key Takeaways

* The problem uses **heap-based optimization** to avoid generating all pairs.
* Works efficiently even for large arrays.
* Time complexity is proportional to `k`, not to the size of the full cross-product.
