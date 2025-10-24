# Split Array Subsequences

**Difficulty:** Medium
**Accuracy:** 56.37%
**Submissions:** 8K+
**Points:** 4

---

### 🧩 Problem Statement

Given a sorted integer array `arr[]` and an integer `k`, determine if it is possible to split the array into one or more consecutive subsequences such that:

* Each subsequence consists of **consecutive integers** (each number is exactly one greater than the previous).
* Every subsequence has a **length of at least k**.

Return `true` if such a split is possible, otherwise return `false`.

---

### 🧠 Examples

**Input:**
`arr = [2, 2, 3, 3, 4, 5], k = 2`
**Output:**
`true`
**Explanation:**
Array can be split into three subsequences of length `k`: `[2,3]`, `[2,3]`, `[4,5]`.

---

**Input:**
`arr = [1, 1, 1, 1, 1], k = 4`
**Output:**
`false`
**Explanation:**
It is impossible to split `arr` into consecutive increasing subsequences of length 4 or more.

---

### ⚙️ Constraints

* 1 ≤ arr.size() ≤ 10^5
* 1 ≤ arr[i] ≤ 10^5
* 1 ≤ k ≤ arr.size()

---

### 💡 Approach

We can use a **hash map of min-heaps** to keep track of subsequences ending with specific numbers.

#### Steps:

1. Traverse through the array elements.
2. For each element `x`:

   * If there exists a subsequence ending with `x-1`, extend it by adding `x`.
   * Otherwise, start a new subsequence with `x`.
3. After processing all elements, check that all subsequences have a length ≥ `k`.

This greedy approach ensures subsequences are extended in the optimal way to form valid consecutive groups.

---

### ✅ Code Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        
        for (int num : arr) {
            if (mp.find(num - 1) != mp.end() && !mp[num - 1].empty()) {
                int len = mp[num - 1].top();
                mp[num - 1].pop();
                mp[num].push(len + 1);
            } else {
                mp[num].push(1);
            }
        }

        // Validate all subsequences
        for (auto& [key, pq] : mp) {
            while (!pq.empty()) {
                if (pq.top() < k) return false;
                pq.pop();
            }
        }

        return true;
    }
};
```

---

### 🕒 Complexity Analysis

* **Time Complexity:** O(n log n) — due to heap operations per element.
* **Space Complexity:** O(n) — for storing subsequences.

---

### 🔍 Example Walkthrough

**Input:** `arr = [2, 2, 3, 3, 4, 5], k = 2`

| Step | Element | Action                    | Subsequences Map |
| ---- | ------- | ------------------------- | ---------------- |
| 1    | 2       | Start new subsequence     | [2]              |
| 2    | 2       | Start another subsequence | [2], [2]         |
| 3    | 3       | Extend both               | [2,3], [2,3]     |
| 4    | 4       | Extend one                | [2,3,4]          |
| 5    | 5       | Extend                    | [2,3,4,5]        |

✅ All subsequences have length ≥ 2 → **Return true**
